#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if(n == 3 && a[2] % 2 == 1){
			puts("-1");
			continue;
		}
		int cnt = 0, maxa = 0;
		long long sum = 0;
		for(int i = 2; i < n; i++){
			maxa = max(maxa, a[i]);
			sum += a[i];
			if(a[i] & 1) cnt++;
		}
		if(maxa <= 1){
			puts("-1");
			continue;
		}
		printf("%lld\n", cnt + (sum - cnt) / 2);
	}
	return 0;
}