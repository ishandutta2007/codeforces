#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const nagai mod = 998244353;
nagai f(nagai x, nagai y) {
	return (x * 124312341234 + y * 12345234 + 1234123) % mod;
}
void test(int n, vector<pair<int,int>> v) {
	vector<nagai>a(n);
	for(auto&[x,y]:v)  {
		 auto t = f(a[x], a[y]);
		 a[x] = t;
		 a[y] = t;
	}
	set<nagai>kek(a.begin(),a.end());
	assert(kek.size()<=2);
}
int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int n;
	 cin >> n;
	 vector<int>pws(n+1);
	 pws[1] = 0;
	 for(int i = 2; i <= n; ++i)
		 pws[i] = 1 + pws[i / 2];
	 vector<pair<int,int>>ans;
	 auto solve2 = [&](auto self, int l, int r) {
		 if (r - l == 1) return;
		 int p = pws[r - l];
		 assert ( r - l == (1 << p));
		 int m = (l + r) / 2;
		 self(self, l, m);
		 self(self, m, r);
		 for(int i=l;i<m;++i)
			 ans.emplace_back(i, i + m - l);
	 };
	 int pp = 1 << pws[n];
	 solve2(solve2, 0, pp);
	 solve2(solve2, n - pp, n);
//	 test(n, ans);
	 cout << ans.size() << '\n';
	 for(auto x : ans)
		 cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	 return 0;
}