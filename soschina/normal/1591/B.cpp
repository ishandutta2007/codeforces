#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = n; i; i--)
			scanf("%d", &a[i]);
		int i = 0, ans = 0;
		for(int j = 1; j <= n; j++)
			if(a[j] > a[i]){
				i = j;
				ans++;
			}
		printf("%d\n", ans - 1);
	}
	return 0;
}