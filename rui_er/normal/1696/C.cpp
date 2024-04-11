// Problem: CF1696C Fishingprince Plays With Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1696C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e4+5;

ll T, n, k, m;
vector<ll> a, b;
vector<tuple<ll, ll> > A, B;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void split(const vector<ll>& from, vector<tuple<ll, ll> >& to) {
	to.clear();
	for(ll i : from) {
		ll val = i, cnt = 1;
		for(;!(val%k);val/=k,cnt*=k);
		if(!to.empty() && val == get<0>(to.back())) {
			auto tmp = to.back();
			get<1>(tmp) += cnt;
			to.pop_back();
			to.push_back(tmp);
		}
		else to.emplace_back(val, cnt);
	}
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		a.resize(n);
		rep(i, 0, n-1) scanf("%lld", &a[i]);
		scanf("%lld", &m);
		b.resize(m);
		rep(i, 0, m-1) scanf("%lld", &b[i]);
		split(a, A);
		split(b, B);
		puts(A==B?"Yes":"No");
	}
	return 0;
}