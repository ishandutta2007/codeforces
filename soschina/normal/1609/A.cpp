#include <cstdio>
using namespace std;
const int N = 16;

int t, n, p;
unsigned int a[N];
unsigned long long two = 1, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0, two = 1;
		scanf("%d", &n);
		p = 1;
		for(int i = 1; i <= n; i++){
			scanf("%u", &a[i]);
			while((a[i] & 1) == 0) a[i] /= 2, two *= 2;
			if(a[i] > a[p]) p = i;
		}
		for(int i = 1; i <= n; i++){
			if(i == p){
				ans += a[i] * two;
			}else ans += a[i];
		}
		printf("%llu\n", ans);
	}
	return 0;
}