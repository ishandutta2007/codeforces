#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;

int t, n, x, i, a[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		long long s = 0;
		for(i = 1; i <= n; i++){
			s += a[n - i];
			if(s < 1ll * i * x){
				printf("%d\n", i - 1);
				break;
			}
		}
		if(i == n + 1) printf("%d\n", n);
	}
	return 0;
}