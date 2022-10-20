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
const int N = 200005;
int type[N], ps[N], v[N], last[N], res[N], a[N];

int main(){
	// File("b");
	int n, m, mx = 0;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	in(m);
	for(int i=1; i<=m; i++){
		in(type[i]);
		if(type[i] == 1)
			in(ps[i]), in(v[i]);
		else in(v[i]);
	}
	memset(res, -1, sizeof res);
	for(int i=m; i>=1; i--){
		if(type[i] == 1 && res[ps[i]] == -1){
			res[ps[i]] = max(v[i], mx);
		}
		else if(type[i] == 2) mx = max(mx, v[i]);
	}
	for(int i=1; i<=n; i++){
		if(res[i] == -1) res[i] = max(a[i], mx);
		printf("%d ", res[i]);
	}
	puts("");
	return 0;
}