#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const int N = 100005;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
int a[N];

int main(){
	// freopen("cf1111b.in", "r", stdin);
	// freopen("cf1111b.out", "w", stdout);
	int n, k, m;
	long double sum = 0;
	in(n); in(k); in(m);
	for(int i=1; i<=n; i++)
		in(a[i]), sum += a[i];
	sort(a+1, a+1+n, greater<int>());
	long double s = 0, ans = sum / n + min(k*1.0, m*1.0 / n);
	for(int i=1; i<=n; i++){
		s += a[i];
		if(n - i <= m)
			ans = max(ans, s / i + min(k*1.0, (m - (n - i)) * 1.0 / i));
	}
	printf("%.12Lf\n", ans);
	return 0;
}