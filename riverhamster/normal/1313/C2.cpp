#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 500005;
ll a[N];
ll f[N], g[N];
int S[N], t = 0;
int fpre[N], gpre[N];
int res[N];

int main(){
	// File("c2");
	int n;
	gi(n);
	for(int i=1; i<=n; i++) gi(a[i]);
	t = 0;
	for(int i=1; i<=n; i++){
		while(t && a[i] < a[S[t]]) --t;
		f[i] = f[S[t]] + a[i] * (i - S[t]);
		fpre[i] = S[t];
		S[++t] = i;
	}
	t = 0;
	S[t] = n + 1;
	for(int i=n; i>=1; i--){
		while(t && a[i] < a[S[t]]) --t;
		g[i] = g[S[t]] + a[i] * (S[t] - i);
		// printf("g[%d] = %lld\n", i, g[i]);
		gpre[i] = S[t];
		S[++t] = i;
	}
	ll Res = max(f[n], g[1]);
	int rp;
	if(Res == f[n]) rp = n;
	else rp = 1;
	for(int i=2; i<n; i++){
		upmax(Res, f[i] + g[i] - a[i]);
		if(Res == f[i] + g[i] - a[i]) rp = i;
	}
	// printf("rp = %d\n", rp);
	int p = rp;
	while(p != 0){
		for(int i=p; i>fpre[p]; i--) res[i] = a[p];
		p = fpre[p];
	}
	p = rp;
	while(p != n + 1){
		for(int i=p; i<gpre[p]; i++) res[i] = a[p];
		p = gpre[p];
	}
	for(int i=1; i<=n; i++) printf("%d ", res[i]);
	putchar('\n');
	return 0;
}