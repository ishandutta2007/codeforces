#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 200005, sqrtV = 1000005;
bool np[sqrtV];
int p[sqrtV], pc = 0;

void primeList(int n){
	for(int i=2; i<=n; i++){
		if(!np[i]) p[++pc] = i;
		for(int j=1; j<=pc && i * p[j] <= n; j++){
			np[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}
set<ll> S;
int n;
ll a[N];
int res = 0x7fffffff;

void work(ll d){
	if(S.count(d)) return ;
	S.insert(d);
	ll sum = 0;
	for(int i=1; i<=n; i++){
		if(a[i] <= d) sum += d - a[i];
		else sum += min(a[i] % d, d - a[i] % d);
	}
	if(sum < res) res = sum;
}

set<ll> factorized;

void fact(ll x){
	for(int i=1; i<=pc; i++){
		if(x % p[i] == 0){
			work(p[i]); x /= p[i];
			while(x % p[i] == 0) x /= p[i];
		}
	}
	if(x != 1) work(x);
}

int main(){
	gi(n);
	primeList(1000000);
	for(int i=1; i<=n; i++) gi(a[i]);
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	for(int i=1; i<=60; i++){
		int pos = rnd() % n + 1;
		fact(a[pos]); fact(a[pos] + 1);
		if(a[pos] != 1) fact(a[pos] - 1);
	}
	printf("%d\n", res);
	return 0;
}