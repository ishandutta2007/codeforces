#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

constexpr int mod = 1e9 + 7;

int mu(int a,int b){
	 return (nagai)a*b%mod;
}

int pw(int a,int b,int c=1){
	for(;b;a=mu(a,a),b /= 2)if(b&1)c=mu(c,a);
	return c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	map<int, int>mp;
	while(t--){
		mp.clear();
		int n, p;
		cin >> n >> p;
		vector<int>k(n);
		for(auto&x:k)
			cin >> x,++mp[x];
		sort(k.begin(),k.end());
		if (p == 1) {
			cout << n % 2 << '\n';
			continue;
		}
		nagai cnt=0;
		int curpw=k.back();
		while(true){
			cnt *= p;
			if (cnt == 0 && mp.size() == 0){
				 cout << 0 << '\n';
				 break;
			}
			if (cnt == 0) {
				curpw = mp.rbegin()->first;
			}
			if (curpw == -1 || cnt > n) {
				nagai ans = mu(cnt % mod, pw(p, curpw));
				for(auto x : mp) {
					ans -= mu(x.second, pw(p, x.first));
					if (ans < 0)
						ans += mod;
				}
				cout << ans << '\n';
				break;
			}
			int& curcnt=mp[curpw];
			auto m = min(cnt, (nagai)curcnt);
			cnt -= m;
			curcnt -= m;
			if (curcnt % 2 == 0) {
				mp.erase(curpw);
			}
			else {
				mp.erase(curpw);
				cnt = 1;
			}
			if (mp.size() == 0) {
				cout << mu(cnt % mod, pw(p, curpw)) << '\n';
				break;
			}
			--curpw;
		}
	}
	return 0;
}