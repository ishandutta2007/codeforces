#include <bits/stdc++.h>
#define maxr 100000
#define endl 1
#define maxn 2000000
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}

short int num[maxr];
template <class T> void print(T x, bool f = 0){
    if (!x) {putchar('0'); if (f) putchar('\n'); return;}
    if (x < 0) putchar('-'), x = -x;
    int s = 0;
    while (x) num[++s] = x % 10, x /= 10; 
    per(i, s, 1) putchar('0' + num[i]);
    if (f) putchar('\n');
}
ll n;
int p[maxn];
bool vis[maxn];
int ct = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++ct] = i;
		rep(j, 1, ct){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main(){
	scanf("%lld", &n);
	if (n == 1) {printf("1"); return 0;}
	init();
	int ans = 0;
	int pi = -1;
	rep(i, 1, ct) if (n % p[i] == 0) {
		pi = p[i];
		while (n % p[i] == 0) n /= p[i]; 
		ans++;
	}
	if (n > 1) ans++;
	if (ans == 1) printf("%lld", (pi == -1) ? n : (ll)pi); 
	else printf("1");
    return 0;
}