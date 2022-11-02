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
int dp[30];
int tmp[30];
char s[NN];
int solve() {
	int n = strlen(s);
	int pos = 26;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(s[i] - 'a' != pos) {
			smax(dp[pos], cnt);
			pos = s[i] - 'a';
			cnt = 1;
		} else cnt++;
	}
	smax(dp[pos], cnt);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n; gn(n);
	scanf("%s", s);
	solve();
	for(int i=1; i<n; i++) {
		scanf("%s", s);
		int n = strlen(s);
		for(int i=0; i<26; i++) tmp[i] = dp[i];
		memset(dp, 0, sizeof dp);
		for(int i=0; i<26; i++) {
			if(!tmp[i]) continue;
			int flag = 1;
			for(int j=0; j<n; j++) if(s[j] - 'a' != i) {
				flag = 0;
				break;
			}
			if(flag) {
				dp[i] = (n + 1) * tmp[i] + n;
			} else {
				int cnt = 0;
				for(int j=0; j<n; j++) {
					if(s[j] - 'a' != i) break;
					cnt++;
				}
				for(int j=n-1; j; j--) {
					if(s[j] - 'a' != i) break;
					cnt++;
				}
				smax(dp[i], 1 + cnt);
			}
		}
		solve();
	}
	int ans = 0;
	for(int i=0; i<26; i++) smax(ans, dp[i]);
	println(ans);
}