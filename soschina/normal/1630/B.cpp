#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 1;

int t, n, m, k, a[N], cnt[N], now, L, R;

int main(){
	scanf("%d", &t);
	while(t--){
		memset(cnt + 1, 0, sizeof(int) * n);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		k = (n + m + 1) / 2;
		L = 1, R = n;
		int l = 0, r = 0;
		now = 0;
		while(true){
			now -= cnt[l++];
			while(r < n && now < k)
				now += cnt[++r];
			if(now >= k){
				if(r - l < R - L)
					L = l, R = r;
			}
			else break;
		}
		printf("%d %d\n", L, R);
		int p = 1, cnt = 0;
		for(int i = 1; i <= n && m > 1; i++){
			if(a[i] >= L && a[i] <= R)
				cnt++;
			else
				cnt--;
			if(cnt == 1){
				printf("%d %d\n", p, i);
				p = i + 1;
				cnt = 0;
				m--;
			}
		}
		printf("%d %d\n", p, n);
	}
	return 0;
}