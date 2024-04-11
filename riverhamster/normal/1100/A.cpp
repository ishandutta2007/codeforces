#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[105];

template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
int n, k;
int work(int b){
	int res = 0;
	for(int i=1; i<=n; i++){
		if(abs(b - i) % k != 0) res += a[i];
	}
	return abs(res);
}

int main(){
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int ans = 0;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
		ans = max(ans, work(i));
	printf("%d\n", ans);
	return 0;
}