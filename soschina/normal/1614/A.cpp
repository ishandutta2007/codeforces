#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 101;

int t, n, l, r, k, x, a[N], len, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		len = 0, ans = 0;
		scanf("%d%d%d%d", &n, &l, &r, &k);
		while(n--){
			scanf("%d", &x);
			if(l <= x && x <= r) a[++len] = x;
		}
		sort(a + 1, a + 1 + len);
		for(int i = 1; i <= len; i++)
			if(a[i] <= k){
				k -= a[i];
				ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}