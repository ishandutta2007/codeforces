#include <bits/stdc++.h>



#define x first

#define y second

#define eps 1e-8

#define pb push_back

#define mod 1000000007

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define bit(x, y) (((x)>>(y))&1)

#define bctz(x) (__builtin_ctz(x))

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctzl(x) (__builtin_ctzll(x))

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



template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<typename T> inline void println(T x) {print(x), putchar('\n');}

template<typename T> inline void printsp(T x) {print(x), putchar(' ');}

template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}

template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=(INT)a*a%m) if (b&1) ans=(INT)ans*a%m;

	return ans;

}

const int N=2222;

char s[N][N];

int d[N][N],flag[N][N];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	

	int n,m;gn(n,m);

	for(int i=1; i<=n; i++) scanf("%s",s[i]+1);

	for(int i=1; i<=n; i++) s[i][n+1]=s[n+1][i]='z';

	d[1][1]=(s[1][1]=='a');

	for(int r=2; r<=n*2; r++) for(int i=1; i<=n; i++){

		int j=r-i;

		if(j>0 && j<=n) {

			if(i>1) smax(d[i][j],d[i-1][j]+('a'==s[i][j]));

			if(j>1) smax(d[i][j],d[i][j-1]+('a'==s[i][j]));

		}

	}

	int k=1;

	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){

		if(i+j-1<=d[i][j]+m) smax(k,i+j);

	}

	

	for(int i=1; i<k; i++) putchar('a');

	

	if(k>1){

		for(int i=1; i<=n; i++){

			int j=k-i;

			if(j>0 && j<=n && i+j-1<=d[i][j]+m) {

				flag[i][j]=1;

			}

		}

	}

	else{

		flag[1][1]=1;

		putchar(s[1][1]);

	}

	

	char t;

	for(int r=max(k,2); r<2*n; r++){

		t='z';

		for(int i=1; i<=n; i++){

			int j=r-i;

			if(j>0 && j<=n && flag[i][j]) {

				smin(t,s[i][j+1]);

				smin(t,s[i+1][j]);

			}

		}

		putchar(t);

		for(int i=1; i<=n; i++){

			int j=r+1-i;

			if(j>0 && j<=n && s[i][j]==t) {

				if(i>1 && flag[i-1][j]) smax(flag[i][j],1);

				if(j>1 && flag[i][j-1]) smax(flag[i][j],1);

			}

		}

	}

	

	return 0;

}