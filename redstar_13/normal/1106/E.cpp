#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define inf 0x3f3f3f3f
#define mod 1000000007
#define sq(x) ((x)*(x))
#define bit(x, y) (((x)>>(y))&1)
#define bctz(x) (__builtin_ctz(x))
#define bclz(x) (__builtin_clz(x))
#define bclzl(x) (__builtin_clzll(x))
#define bctzl(x) (__builtin_ctzl(x))
#define bpt(x) (__builtin_popcount(x))
#define bptl(x) (__builtin_popcountll(x))
#define PQ priority_queue<pii, vector<pii>, greater<pii> >

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
template <class T1, class T2, class T3> inline void gn(T1 &x1, T2 &x2, T3 &x3) {gn(x1, x2), gn(x3);}
template <class T1, class T2, class T3, class T4> inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {gn(x1, x2, x3), gn(x4);}
template <class T1, class T2, class T3, class T4, class T5> inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {gn(x1, x2, x3, x4), gn(x5);}

template <class T> inline void print(T x) {if(x<0) {putchar('-'); return print(-x);} if(x<10) {putchar('0'+x); return ;} print(x/10); putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}
template <class T> inline void printsp(T x) {print(x); putchar(' ');}
template <class T1, class T2> inline void print(T1 x1, T2 x2) {printsp(x1), println(x2);}
template <class T1, class T2, class T3> inline void print(T1 x1, T2 x2, T3 x3) {printsp(x1), printsp(x2), println(x3);}
template <class T1, class T2, class T3, class T4> inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {printsp(x1), printsp(x2), printsp(x3), println(x4);}
template <class T1, class T2, class T3, class T4, class T5> inline void print(T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {printsp(x1), printsp(x2), printsp(x3), printsp(x4), println(x5);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100010
#define MM 210
#define ls (u<<1)
#define rs (ls|1)
#define mid (L + R >> 1)

int flag[NN * 4];
int id[NN * 4];
int s[NN], t[NN], d[NN], w[NN];
int pos[NN];
INT dp[NN][MM];

int build(int u, int L, int R) {
	if(L + 1 == R) {
		pos[L] = u;
		return 0;
	}
	build(ls, L, mid);
	build(rs, mid, R);
	return 0;
}

int comp(int u, int v) {
	if(w[u] > w[v]) return u;
	if(w[u] < w[v]) return v;
	if(d[u] > d[v]) return u;
	return v;
}

int push_down(int u) {
	if(!flag[u]) return 0;
	id[ls] = comp(id[ls], flag[u]);
	id[rs] = comp(id[rs], flag[u]);
	flag[ls] = comp(flag[ls], flag[u]);
	flag[rs] = comp(flag[rs], flag[u]);
	flag[u] = 0;
}

int push_up(int u) {
	id[u] = comp(id[ls], id[rs]);
	return 0;
}

int update(int u, int L, int R, int st, int ed, int x) {
	if(L >= ed || R <= st) return 0;
	if(L >= st and R <= ed) {
		id[u] = comp(id[u], x);
		flag[u] = comp(flag[u], x);
		return 0;
	}
	push_down(u);
	update(ls, L, mid, st, ed, x);
	update(rs, mid, R, st, ed, x);
	push_up(u);
	return 0;
}

int calc(int u, int L, int R) {
	if(L + 1 == R) return 0;
	push_down(u);
	calc(ls, L, mid);
	calc(rs, mid, R);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m, k;
	gn(n, m, k);
	build(1, 1, n+1);
	for(int i=1; i<=k; i++) {
		gn(s[i], t[i], d[i], w[i]);
		update(1, 1, n+1, s[i], t[i] + 1, i);
	}
	
	calc(1, 1, n+1);
	
	for(int i=n; i; i--) {
		for(int j=0; j<=m; j++) {
			int x = id[pos[i]];
			if(x == 0) {
				dp[i][j] = dp[i+1][j];
				continue;
			}
			dp[i][j] = dp[d[x]+1][j] + w[x];
			if(!j) continue;
			smin(dp[i][j], dp[i+1][j-1]);
		}
	}
	
	println(dp[1][m]);
}