#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int mod=1e9+7;

nagai md(nagai& x){
	return x %= mod;
}
nagai md(const nagai& x){
	return x % mod;
}

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int t;
	 cin >> t;
	 while(t--) {
		 const int LG = 62;
		 int n;
		 cin >> n;
		 vector<nagai>a(n);
		 for(auto&x:a)
			 cin >> x;
		 vector<int>cnt(LG);
		 for(auto x : a) 
			 for(int i=0;i<LG;++i) 
				 if (x >> i & 1) 
					 ++cnt[i];
		 nagai ans = 0;
		 for(auto x : a) {
			 nagai s1=0,s2=0;
			 for(int i =0;i<LG;++i)  {
				 if (x >> i & 1) {
					 s1 += n * md(1LL << i);
					 md(s1);
					 s2 += cnt[i] * md(1LL << i);
					 md(s2);
				 }
				 else {
					 s1 += cnt[i] * md(1LL << i);
					 md(s1);
				 }
			 }
			 ans += s1 * s2 ;
			 md(ans);
		 }
		 cout << ans << '\n';
	 }
	 return 0;
}