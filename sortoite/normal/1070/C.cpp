#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 1010101

vector<pii> _add[NN], _del[NN];
INT sum[NN], num[NN];

inline void update(int u, int c, INT x) {
	for(; u<NN; u+=u&-u) {
		num[u]+=c;
		sum[u]+=x;
	}
}

inline INT calc_num(int u) {
	INT ans=0;
	for(; u; u-=u&-u) ans+=num[u];
	return ans;
}
inline INT calc_sum(int u) {
	INT ans=0;
	for(; u; u-=u&-u) ans+=sum[u];
	return ans;
}

inline void insert(int c, int p) {
	update(p, c, (INT)c*p);
}
inline void erase(int c, int p) {
	update(p, -c, -(INT)c*p);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, k, m; scanf("%d %d %d", &n, &k, &m);
	while(m--) {
		int L, R, c, p; scanf("%d %d %d %d", &L, &R, &c, &p);
		_add[L].pb(pii(c, p));
		_del[R+1].pb(pii(c, p));
	}
	
	INT ans=0;
	for(int I=1; I<=n; I++) {
		for(pii p: _add[I]) insert(p.x, p.y);
		for(pii p: _del[I]) erase(p.x, p.y);
		
		int st=0, ed=1000000;
		while(ed-st>1) {
			int md=st+ed>>1;
			if(calc_num(md)>=k) ed=md;
			else st=md;
		}
		ans+=calc_sum(ed);
		ans-=(INT)max(0LL, (calc_num(ed)-k))*ed;
	}
	printf("%I64d\n", ans);
}