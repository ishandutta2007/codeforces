#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

vector<int> sales[500001];
bool possible(int days, vector<int> neededOfType) {
	vector<int> saleDay;
	for (int i=0; i<neededOfType.size(); i++) {
		saleDay.push_back(-1);
	}
	for (int i=1; i<=days; i++)
		for (int j:sales[i])
			saleDay[j]=i;

	int money=0;
	for (int day=1; day<=days; day++) {
		money++;
		for (int item:sales[day]) {
			if (day!=saleDay[item]) continue;
			int toBuy=min(money, neededOfType[item]);
			money-=toBuy;
			neededOfType[item]-=toBuy;
		}
	}
	ll stillNeed=0;
	for (int &i:neededOfType)
		stillNeed+=i;
	return money>=2*stillNeed;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	int n, m; cin>>n>>m;
	vector<int> neededOfType;
	for (int i=0; i<n; i++) {
		int v; cin>>v;
		neededOfType.push_back(v);
	}
	vector<ii> allSales;//day, item
	for (int i=0; i<m; i++) {
		int day, item; cin>>day>>item;
		item--;
		sales[day].push_back(item);
	}
	int minDay=1, maxDay=500000;
	while (minDay!=maxDay) {
		int midDay=(minDay+maxDay)/2;
		if (possible(midDay, neededOfType)) {
			maxDay=midDay;
		}
		else {
			minDay=midDay+1;
		}
	}
	cout<<minDay<<endl;
	return 0;
}