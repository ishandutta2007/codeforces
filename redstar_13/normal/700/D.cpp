#include<bits/stdc++.h>

#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define bpt(x) (__builtin_popcount(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bctz(x) (__builtin_ctz(x))

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100011
#define MM 333

struct query {
	int l, r, id;
	void input(int i) {
		gn(l); gn(r); id=i;
	}
	bool operator < (const query &tmp) const {
		if(l/MM == tmp.l/MM) return r < tmp.r;
		return l/MM < tmp.l/MM;
	}
} qu[NN];
int a[NN];
int n;
int ans[NN];
int now[NN];
int cnt[NN];
int big[NN];
int nb;
int flag[NN];
int tmp[NN];

inline void poke(int u, int d) {
	u=a[u];
	cnt[now[u]]--;
	now[u] += d;
	cnt[now[u]]++;
	if(flag[u]==0 and now[u] >= MM) flag[u]=1, big[nb++] = u;
}

inline int calc() {
	int pre=0;
	priority_queue<int, VI, greater<int> > pq;
	int ans=0, add;
	for(int i=1, ni; i<MM; i++) if(tmp[i]+=cnt[i]) {
		if(pre) {
			tmp[i]--;
			add=i+pre;
			ans+=add;
			if(add<MM) tmp[add]++;
			else pq.push(add);
			pre=0;
			if(!tmp[i]) continue;
		}
		add=ni=i<<1;
		ans+=add*(tmp[i]>>1);
		if(ni<MM) tmp[ni] += (tmp[i]>>1);
		else {add=tmp[i]>>1; while(add--) pq.push(ni);}
		if(tmp[i]&1) pre=i;
		tmp[i]=0;
	}
	if(pre) pq.push(pre);
	for(int i=0; i<nb; i++) if(now[big[i]]>=MM) pq.push(now[big[i]]);
	int x, y;
	while(sz(pq)>1) {
		x=pq.top(); pq.pop();
		y=pq.top(); pq.pop();
		ans+=add=x+y;
		pq.push(add);
	}
	return ans;
}


int solve() {
	cin >> n;
	for(int i=1; i<=n; i++) gn(a[i]);
	int q;
	
	cin >> q;
	for(int i=0; i<q; i++) {
		qu[i].input(i);
	}
	sort(qu, qu+q);
	int st=1, ed=0;
	for(int i=0; i<q; i++) {
		int L=qu[i].l, R=qu[i].r, id=qu[i].id;
		while(ed>R) poke(ed--, -1);
		while(ed<R) poke(++ed, 1);
		while(st>L) poke(--st, 1);
		while(st<L) poke(st++, -1);
		ans[id] = calc();
	}
	for(int i=0; i<q; i++) {
		println(ans[i]);
	}
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}