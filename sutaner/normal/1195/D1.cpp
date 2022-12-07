#include <bits/stdc++.h>
#define maxn 200005
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define M 998244353
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int num[11];
int a[maxn];
int len[maxn];
int n;

inline void mo(ll& x){
	x = (x >= M) ? (x - M) : x;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("D.in", "r", stdin);
    #endif
	read(n);
	ll ans = 0;
	
	rep(i, 1, n) {
		read(a[i]);
		int s = 0, x = a[i];
		while (x) s++, x /= 10;
		num[s]++;
		len[i] = s;
	}
	
	rep(i, 1, n){
		int x = a[i];
		ll tenmi = 10, now = 0;
		ans += x * tenmi % M * num[1] % M, mo(ans);
		rep(j, 2, 10){
			now += x % 10 * tenmi % M, mo(now), x /= 10;
			(tenmi *= 100) %= M; 
			ans += ((now + tenmi * x % M) % M * num[j] % M), mo(ans);
		}
	}//first
	
	rep(i, 1, n){
		int x = a[i];
		ll tenmi = 1, now = 0;
		rep(j, 1, 10){
			now += x % 10 * tenmi % M, mo(now), x /= 10;
			(tenmi *= 100) %= M; 
			ans += ((now + tenmi * x % M) % M * num[j] % M), mo(ans);
		}
	}//second
	
	printf("%lld", ans);
	return 0;
}