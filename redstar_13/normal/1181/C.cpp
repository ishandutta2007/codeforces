#include<bits/stdc++.h>

#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define bpt(x) (__builtin_popcount(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bctz(x) (__builtin_ctz(x))
#define SZ(a) ((int)a.size())
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

#define NN 1011
char s[NN][NN];
int n, m;
int nxt[NN][NN];
int pos[333];

int ok(char a, char b, char c) {
	if(a==b) return 0;
	if(b==c) return 0;
	return 1;
}

INT ans;

int calc(int l, int r, int c) {
	int len = r-l;
	int st=l-len;
	int ed=r+len;
	if(st<0 or ed>n) return 0;
	int mn=44444;
	for(int i=st; i<l; i++) if(s[i][c] != s[st][c]) return 0;
	for(int i=r; i<ed; i++) if(s[i][c] != s[r][c]) return 0;
	if(ok(s[st][c], s[l][c], s[r][c])==0) return 0;
	for(int i=st; i<ed; i++) smin(mn, nxt[i][c]);
	ans += mn;
}

int solve() {
	cin >> n >> m;
	for(int i=0; i<n; i++) scanf("%s", s[i]);
	for(int i=0; i<n; i++) {
		nxt[i][m-1]=1;
		for(int j=m-2; j>=0; j--) {
			if(s[i][j] == s[i][j+1]) nxt[i][j] = nxt[i][j+1]+1;
			else nxt[i][j] = 1;
		}
	}
	for(int j=0; j<m; j++) {
		for(int i=0, ni=0; i<n; i=ni) {
			while(ni<n and s[i][j] == s[ni][j]) ni++;
			calc(i, ni, j);
		}
	}
	cout << ans << endl;
}



int main() {
#ifndef	ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}