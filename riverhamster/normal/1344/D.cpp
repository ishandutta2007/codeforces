// Codeforces contest template
#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

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

const int N = 100005;

int n;
ll k;
ll a[N], b[N], c[N];

bool check(ll x, ll *b){
	ll sum = 0;
	for(int i=1; i<=n; i++){
		i128 de = 9 - (i128)12 * (1 - a[i] + x);
		if(de < 0) b[i] = a[i];
		else b[i] = (-3 + sqrt((long double)de)) / 6;
		upmax(b[i], 0LL); upmin(b[i], a[i]);
		sum += b[i];
	}
	return sum <= k;
}

int main(){
	// File("d");
	gi(n); gi(k);
	for(int i=1; i<=n; i++) gi(a[i]);
	ll l = -3000000003000000000LL, r = 3000000003000000000LL, mid, res = l;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid, b)){
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	check(res, b);
	ll sum = accumulate(b + 1, b + 1 + n, 0LL);
	ll d = k - sum;
	check(res - 1, c);
	for(int i=1; i<=n; i++){
		if(d >= c[i] - b[i]) wi(c[i]), d -= c[i] - b[i], SP;
		else if(d == 0) wi(b[i]), SP;
		else wi(b[i] + d), d = 0, SP;
	}
	EL;
	return 0;
}