#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define fi first
#define se second

const int S=2020;
const int N=2*S+5;
bool bad[N][N];

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int n, m;
	 cin >> n >> m;
	 vector<pair<int,int>>p1(n),p2(m);
	 for(int i = 0; i < n; ++i)
		 cin >> p1[i].first >> p1[i].second;
	 for(int i=0;i<m;++i)
		 cin >> p2[i].fi >> p2[i].se;
	 vector<pair<int, int>>p;
	 for(int i=0;i<n;++i) {
		 for(int j=0;j<m;++j) {
			 int kek = p2[j].fi+1 - p1[i].fi;
			 int mem = p2[j].se+1 - p1[i].se;
			 if (kek >= 0 || mem >= 0) {
				 kek = max(kek, 0);
				 mem = max(mem, 0);
				 p.emplace_back(kek, mem);
			 }
		 }
	 }
	 sort(p.begin(),p.end());
#define stack aeus
	 vector<pair<int,int>>stack;
	 for(auto pp : p) {
		 while(stack.size() && stack.back().se <= pp.se)
			 stack.pop_back();
		 stack.push_back(pp);
	 }
	 int lst=0;
	 int ans =0x3f3f3f3f;
	 for(auto x : stack) {
		 ans = min(ans, lst + x.se);
		 lst = x.fi;
	 }
	 ans = min(ans, lst);
	 cout << ans << '\n';
}