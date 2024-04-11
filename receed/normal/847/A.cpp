#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	vector<int> starters;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first--;
		a[i].second--;
		if(a[i].first == -1){
			starters.push_back(i);
			
		}
		
	}
	int v;
	for(int i=0; i<starters.size()-1; i++){
		v = starters[i];
		while(a[v].second!=-1){
			v = a[v].second;
		}
		a[v].second = starters[i+1];
		a[starters[i+1]].first=v;
	}
	for(int i=0; i<n; i++)
		cout << a[i].first+1 << ' '<< a[i].second+1 << endl;
		return 0;
}