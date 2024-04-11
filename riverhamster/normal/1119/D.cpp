#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 100005;
ll a[N], d[N];
struct Que{
	ll x, ans;
	int id;
}q[N];
bool cmpx(Que a, Que b){return a.x < b.x;}
bool cmpid(Que a, Que b){return a.id < b.id;}

int main(){
	// File("d");
	int n, qs;
	ll l;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	sort(a+1, a+1+n);
	for(int i=1; i<n; i++) d[i] = a[i+1] - a[i];
	sort(d+1, d+n);
	in(qs);
	for(int i=1; i<=qs; i++) in(l), in(q[i].x), q[i].x -= l-1, q[i].id = i;
	sort(q+1, q+1+qs, cmpx);
	ll ans = 0;
	int p = 1;
	for(int i=1; i<=qs; i++){
		// printf("Query %lld id = %d\n", q[i].x, q[i].id);
		while(q[i].x >= d[p] && p < n) ans += d[p], ++p;
		q[i].ans = q[i].x * (n - p) + ans + q[i].x;
		// printf("Answer is %lld\n", q[i].ans);
	}
	sort(q+1, q+1+qs, cmpid);
	for(int i=1; i<=qs; i++) printf("%lld ", q[i].ans);
	puts("");
	return 0;
}