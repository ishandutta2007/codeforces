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

const int NN = 200011;
char s[NN];
int n;
char t[NN];

int solve() {
    int now=0;
    int st=-1, ed=-1;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') now++;
        else now--;
        if(now<0) {
            st=i;
            break;
        }
    }
    if(st == -1) {
        if(now == 0) return 1;
        return 0;
    }
    now=0;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == ')') now++;
        else now--;
        if(now<0) {
            ed=i;
            break;
        }
    }
    if(ed == -1) return 0;
    if(st >= ed) return 0;
    int nn=0;
    for(int i=0; i<st; i++) t[nn++] = s[i];
    t[nn++] = s[ed];
    t[nn++] = s[st];
    for(int i=st+1; i<ed; i++) t[nn++] = s[i];
    for(int i=ed+1; i<n; i++) t[nn++] = s[i];
    now = 0;
    for(int i=0; i<n; i++) {
        if(t[i] == '(') now++;
        else now--;
        if(now<0) {
            return 0;
        }
    }
    return now==0;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
    cin >> n;
    scanf("%s", s);
    if(solve()) puts("Yes");
    else puts("No");
	return 0;
}