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

INT p;
inline INT mul(const INT &x, const INT &y, INT mod) {
    return ((x*y-(INT)(x/(long double)mod*y+1e-5)*mod)%mod+mod)%mod;
}

inline INT power(INT a, INT b, INT ans=1) {
    for (; b; b>>=1, a=mul(a, a, p)) if (b&1) ans=mul(ans, a, p);
    return ans;
}

const int NN = 1<<20+3;
int m;
int n;
INT t;
INT e[NN];
int b[22];
INT x[22];

void fwt(INT e[], int n, INT mod) {
    for (int m=1, n1=2; n1<=n; m=n1, n1<<=1) {
        for (int i=0; i<n; i+=n1) for (int j=0; j<m; j++) {
            const INT x = e[i|j], y = e[i|j|m];
            e[i|j]=x+y;
            e[i|j|m]=x-y;
            if (e[i|j]>=mod) e[i|j]-=mod;
            if (e[i|j|m]<0) e[i|j|m]+=mod;
        }
    }
}

int solve() {
	cin >> m >> t >> p; 
	n = 1<<m;
	p *= n;
	for(int i=0; i<n; i++) gn(e[i]), e[i]%=p;
	for(int i=0; i<=m; i++) gn(b[i]);
	int all;
	for(int i=0; i<=m; i++) {
		all = (1 << i) - 1;
		for(int j=0; j<n; j++) {
			x[i] = x[i] + (1 - 2*(bpt(all & j) & 1)) * b[bpt(j)];
        }
        x[i] %= p;
        if(x[i] < 0) x[i] += p;
        x[i]=power(x[i], t);
	}
	
	fwt(e, n, p);
    for(int i=0; i<n; i++) e[i] = mul(e[i], x[bpt(i)], p);
    fwt(e, n, p);

    for (int i=0; i<n; i++) println(e[i]/n);
    
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}