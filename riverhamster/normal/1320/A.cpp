#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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

const int N = 200005;

int last[N * 8];
ll f[N];

int main(){
	// File("a");
	int n;
	gi(n);
	ll res = 0;
	for(int i=1; i<=n; i++){
		int c;
		gi(c);
		int v = i - c + N * 2;
		f[i] = f[last[v]] + c;
		last[v] = i;
		upmax(res, f[i]);
	}
	printf("%lld\n", res);
	return 0;
}