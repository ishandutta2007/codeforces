#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, tmp, zero, x[N], y[N], maxx, maxy;
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		zero = 0;
		*x = *y = 0;
		maxx = maxy = 0;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++){
			scanf("%d", &tmp);
			if(tmp > 0){
				x[++*x] = tmp;
				maxx = max(maxx, tmp);
			}else if(tmp < 0){
				y[++*y] = -tmp;
				maxy = max(maxy, -tmp);
			}else zero++;
		}
		sort(x + 1, x + 1 + *x);
		sort(y + 1, y + 1 + *y);
		int xrem = *x % k;
		for(int i = xrem; i <= *x; i += k)
			if(i) ans += x[i];
		int yrem = *y % k;
		for(int i = yrem; i <= *y; i += k)
			if(i) ans += y[i];
		printf("%lld\n", ans * 2 - max(maxx, maxy));
	}
	return 0;
}