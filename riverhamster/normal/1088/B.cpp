#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];

int main(){
	// freopen("cf1088b.in", "r", stdin);
	// freopen("cf1088b.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	a[0] = 0;
	int now = 1;
	for(int i=1; i<=k; i++){
		while(a[now] == a[now - 1] && now <= n) ++now;
		if(now > n){
			puts("0");
			continue;
		}
		printf("%d\n", a[now] - a[now-1]);
		++now;
	}
	return 0;
}