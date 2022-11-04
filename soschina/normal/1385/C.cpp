#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], p;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", a + i);
		p = n;
		while(p > 1 && a[p - 1] >= a[p]) p--;
		while(p > 1 && a[p - 1] <= a[p]) p--;
		printf("%d\n", p - 1);
	}
	return 0;
}