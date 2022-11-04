#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1, K = 6;

int t, n, k, z, a[N], rep, sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%d%d", &n, &k, &z);
		++k;
		for(int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for(int time = max((k - n + 1) / 2, 0); time <= min(z, (k - 1) / 2); time++){
			if(time && k - 2 * (time - 1)  - 1 <= n){
				rep = 0, sum = a[1] + a[k - 2 * (time - 1)  - 2];
				for(int j = 2; j <= k - 2 * (time - 1)  - 1; j++){
					sum += a[j];
					rep = max(rep, a[j - 1] + a[j]);
				}
				ans = max(ans, sum + rep * (time - 1));
			}
			if(k - 2 * time <= n){
				rep = 0, sum = a[1];
				for(int j = 2; j <= k - 2 * time; j++){
					sum += a[j];
					rep = max(rep, a[j - 1] + a[j]);
				}
				ans = max(ans, sum + rep * time);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}