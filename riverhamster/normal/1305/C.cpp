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
const int N = 1005;
int cnt[N];
int n, m;

inline int P(int x, int y){
	printf("P %d %d\n", x, y);
	int res = 1;
	for(; y; y>>=1, x = (x * x) % m) if(y & 1) res = (res * x) % m;
	return res;
}

int a[200005];

int main(){
	// File("c");
	gi(n); gi(m);
	for(int i=1; i<=n; i++){
		gi(a[i]);
		++cnt[a[i] % m];
		if(cnt[a[i] % m] > 1){
			puts("0");
			return 0;
		}
	}
	int res = 1;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			res = (1LL * res * abs(a[i] - a[j])) % m;
	wi(res); EL;
	return 0;
}