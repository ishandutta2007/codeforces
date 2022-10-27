#include <bits/stdc++.h>
using namespace std;
bool dp[10002][2002];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0;i<n;i++)cin>>a[i];
		set<pair<int,int> > s;
		for(int i=0;i<n;i++)
			if(a[i]>0) s.insert(make_pair(a[i],i+1));

		vector<pair<int,int> > ans;
		while(s.size()>=2) {
			auto it1 = (*s.rbegin()); s.erase(it1);
			auto it2 = (*s.rbegin()); s.erase(it2);
			ans.emplace_back(it1.second, it2.second);
			if (it1.first > 1) s.insert(make_pair(it1.first-1, it1.second));
			if (it2.first > 1) s.insert(make_pair(it2.first-1, it2.second));
		}
		cout << ans.size() << "\n";
		for (auto [u, v]: ans) cout << u << " " << v << "\n"; 
	}		
}
/*
L
dp[i][j]
*/