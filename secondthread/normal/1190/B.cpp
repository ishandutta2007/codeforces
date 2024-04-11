#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//if zero pair, a loses
	//if three of a kind, a loses
	//if more than one pair, a loses
	//if one pair x, x and x-1 exists, a loses
	//count total stones, subtract n*(n-1)/2, check pairity
	ll total=0;
	ll n; cin>>n;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp; a.push_back(temp);
		total+=temp;
	}
	sort(a.begin(), a.end());
	bool impossible=false;
	int pairCount=0;
	for (int i=0; i<n; i++) {
		if (i+1<n && a[i]==0 && a[i+1]==0) impossible=true;
		if (i+2<n&&a[i]==a[i+2]) impossible=true;
		if (i+1<n&&i>0 && a[i]==a[i+1] && a[i]-1==a[i-1]) impossible=true;
		if (a[i]==a[i+1]) pairCount++;
	}
	if (pairCount>1) impossible=true;

	total-=(n)*(n-1)/2;
	if (total%2==0) impossible=true;
	cout<<(impossible?"cslnb\n":"sjfnb\n");
	return 0;
}