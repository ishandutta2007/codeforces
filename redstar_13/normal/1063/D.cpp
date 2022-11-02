#include<bits/stdc++.h>



#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define mod 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define sz(a) ((int)a.size())

#define eps 1e-8

#define x first

#define y second

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) ((x) ? (__builtin_clzll(x)) : 0)

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define shit(a) (1 << (a))

#define rev(a) (power(a, mod-2, mod))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;



typedef double DO;

typedef long long INT;

typedef pair<int, int> pii;

typedef pair<pii, int> ppi;

typedef vector<int> VI;



template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template <class T> inline void println(T x) {print(x); putchar('\n');}

template <class T> inline void printsp(T x) {print(x); putchar(' ');}

template <class T1, class T2> inline void print(T1 x1, T2 x2) {printsp(x1), println(x2);}

template <class T1, class T2, class T3> inline void print(T1 x1, T2 x2, T3 x3) {printsp(x1), printsp(x2), println(x3);}

template <class T1, class T2, class T3, class T4> inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {printsp(x1), printsp(x2), printsp(x3), println(x4);}

int power(int a, int b, int m, int ans=1) {

	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;

	return ans;

}



INT n, l, r, k;

INT m;



int main() {

#ifndef	ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	gn(n, l); gn(r, k);

	m = (r-l+1+n)%n;

	INT ans=-1;

	INT res=-1;

	if(m==0) {

		for(int i=1; (INT)i*i<=k+1; i++) {

			if(k%i==0) {

				if(i>=n and i<=2*n) smax(ans, i);

				if(k/i>=n and k/i<=2*n) smax(ans, k/i);							

			}

			if((k+1)%i==0) {

				if(i>n and i<=2*n) smax(ans, i);

				if((k+1)/i>n and (k+1)/i<=2*n) smax(ans, (k+1)/i);



			}

		}

		if(ans==-1) return puts("-1");

		return cout << ans-n << endl,0;

	}

	

	for(INT l=n, r=n; l<=2*n; l=r+1) {

		if(k/l) r=k/(k/l);

		else r=2*n;

		smin(r, 2*n);

		INT l1, l2, r1, r2;

		INT st=l, ed=r+1;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(k%mid>=m) st=mid;

			else ed=mid; 

		}

		if(k%st<m) continue;

		r1=st;

		st=l-1; ed=r;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(k%mid<=2*m) ed=mid;

			else st=mid;

		}

		if(k%ed>2*m) continue;

		l1=ed;

		st=l-1, ed=r;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(mid-k%mid>=n-m) ed=mid;

			else st=mid; 

		}

		if(ed-k%ed<n-m) continue;

		l2=ed;

		

		st=l; ed=r+1;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(mid-k%mid<=2*(n-m)) st=mid;

			else ed=mid;

		}

		r2 = st;

		if(st-k%st>2*(n-m)) continue;

		smax(l1, l2);

		smin(r1, r2);

		if(r1>=l1) smax(ans, r1);

	}

	

	

	

	for(INT l=n, r=n; l<=2*n; l=r+1) {

		if(k/l) r=k/(k/l);

		else r=2*n;

		smin(r, 2*n);

		INT l1, l2, r1, r2;

		INT st=l, ed=r+1;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(k%mid>=m) st=mid;

			else ed=mid; 

		}

		if(k%st<m) continue;

		r1=st;

		st=l-1; ed=r;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(k%mid<2*m) ed=mid;

			else st=mid;

		}

		if(k%ed>=2*m) continue;

		l1=ed;

		st=l-1, ed=r;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(mid-k%mid-1>=n-m) ed=mid;

			else st=mid; 

		}

		if(ed-k%ed-1<n-m) continue;

		l2=ed;

		

		st=l; ed=r+1;

		while(ed > st + 1) {

			INT mid = st + ed >> 1;

			if(mid-k%mid-1<=2*(n-m)) st=mid;

			else ed=mid;

		}

		r2 = st;

		if(st-k%st-1>2*(n-m)) continue;

		smax(l1, l2);

		smin(r1, r2);

		if(r1>=l1) smax(res, r1);

	}

	smax(ans, res);

	if(ans == -1) return puts("-1");

	cout << ans - n << endl;

	return 0;

}