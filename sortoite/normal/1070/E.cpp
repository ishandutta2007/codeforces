#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 202020

int n, m;
INT t;
vector<int> vec, id[NN];
int num[NN];
INT sum[NN];

inline void update(int u, int c) {
	for(; u<=n; u+=u&-u) num[u]++, sum[u]+=c;
}
inline int calc_num(int u) {
	int ans=0;
	for(; u; u-=u&-u) ans+=num[u];
	return ans;
}
inline INT calc_sum(int u) {
	INT ans=0;
	for(; u; u-=u&-u) ans+=sum[u];
	return ans;
}

inline INT calc_time(int u) {
	int N=calc_num(u);
	if(N<=m) return 0;
	if(N%m) N=N/m*m;
	else N-=m;
	int st=0, ed=n;
	while(ed-st>1) {
		int md=st+ed>>1;
		if(calc_num(md)>=N) ed=md;
		else st=md;
	}
	return calc_sum(ed);
}

inline void solve() {
	scanf("%d %d %I64d", &n, &m, &t);
	vec.clear();
	for(int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		vec.pb(x);
		id[x].pb(i);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end())-vec.begin());
	
	pii ans=pii(0, 1);
	for(int i=1; i<=n; i++) num[i]=0, sum[i]=0;
	for(int c: vec) {
		for(int x: id[c]) update(x, c);
		int st=0, ed=n+1;
		while(ed-st>1) {
			int md=st+ed>>1;
			if(calc_sum(md)+calc_time(md)<=t) st=md;
			else ed=md;
		}
		id[c].clear();
		int sum=calc_num(st);
		if(sum>ans.x) ans=pii(sum, c);
	}
	printf("%d %d\n", ans.x, ans.y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int T; scanf("%d", &T);
	while(T--) solve();
}