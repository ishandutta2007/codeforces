#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int> a(n*n);
	vector<int> cs(1001, 0);
	for (int i=0; i<n*n; i++) cin>>a[i];
	for (int i:a) cs[i]++;
	vector<int> fours, ones, twos;
	for (int val=0; val<cs.size(); val++) {
		int i=cs[val];
		while (i>=4) {
			fours.push_back(val);
			i-=4;
		}
		while (i>=2) {
			twos.push_back(val);
			i-=2;
		}
		while (i>=1) {
			ones.push_back(val);
			i--;
		}
	}

	vector<vector<int>> ans(n, vector<int>(n, 0));
	if (n%2==0) {
		//even by even
		if (!ones.empty() || !twos.empty()) {
			cout<<"No\n"; return 0;
		}
		int x=0, y=0;
		for (int i:fours) {
			ans[x][y]=ans[x][n-1-y]=ans[n-1-x][y]=ans[n-1-x][n-1-y]=i;
			x++;
			if (x>=n/2) {
				x=0;
				y++;
			}
		}
	}
	else {
		if (ones.size()!=1) {
			cout<<"No\n"; return 0;
		}
		int nFoursAllowed=(n-1)*(n-1)/4;
		int x=0, y=0;
		for (int i:fours) {
			if (nFoursAllowed>0) {
				nFoursAllowed--;
				ans[x][y]=ans[x][n-1-y]=ans[n-1-x][y]=ans[n-1-x][n-1-y]=i;
				x++;
				if (x>=n/2) {
					x=0;
					y++;
				}
			}
			else {
				twos.push_back(i);
				twos.push_back(i);
			}
		}
		if (nFoursAllowed!=0) {
			cout<<"No\n"; return 0;
		}
		ans[n/2][n/2]=ones[0];
		for (int i=0; i<n/2; i++) {
			ans[n/2][i]=ans[n/2][n-i-1]=twos[i];
		}
		for (int i=0; i<n/2; i++) {
			ans[i][n/2]=ans[n-i-1][n/2]=twos[i+n/2];
		}

	}
	cout<<"Yes\n";
	for (int x=0; x<n; x++) {
		for (int y=0; y<n; y++) {
			cout<<ans[x][y]<<" ";
		}
		cout<<'\n';
	}

	return 0;
}