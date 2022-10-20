#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 50005;
int a[N];

int main(){
	// freopen("cf1113b.in", "r", stdin);
	// freopen("cf1113b.out", "w", stdout);
	int n, s = 0, res;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]), s += a[i];
	sort(a+1, a+1+n);
	res = s;
	for(int i=2; i<=n; i++){
		for(int j=1; j*j<=a[i]; j++)
			if(a[i] % j == 0){
				// printf("a[%d] /= %d a[%d] /= %d\n", i, j, i, a[i]/j);
				res = min(res, s - (a[i] - a[i]/j) + a[1] * (j-1));
				// printf("res = %d\n", res);
				res = min(res, s - (a[i] - j) + a[1] * (a[i]/j - 1));
				// printf("res = %d\n", res);
			}
	}
	printf("%d\n", res);
	return 0;
}