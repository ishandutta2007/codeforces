#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 1000005;
bool np[N];
int p[N], ps = 0;

void plist(int N){
	for(ll i=2; i<=N; i++){
		if(!np[i]) p[++ps] = i;
		for(int j=1; j<=ps && i * p[j] <= N; j++){
			np[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}
const int R = 10005;
int ra[R], rb[R], m = 0;

int main(){
	// File("d");
	int n, f;
	bool flag;
	in(n);
	plist(n*2);
	for(int i=n; i<=n+(n/2); i++)
		if(!np[i]){
			f = i;
			break;
		}
	for(int i=1; i<n; i++) ra[++m] = i, rb[m] = i+1;
	ra[++m] = n; rb[m] = 1;
	for(int i=n+1; i<=f; i++){
		ra[++m] = i-n;
		rb[m] = i-n + n/2;
	}
	printf("%d\n", m);
	for(int i=1; i<=m; i++) printf("%d %d\n", ra[i], rb[i]);
	return 0;
}