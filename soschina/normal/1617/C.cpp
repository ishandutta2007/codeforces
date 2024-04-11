#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], ans;
bool vis[N];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		memset(vis + 1, 0, sizeof(bool) * n);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n && a[i] <= n; i++)
			vis[a[i]] = true, ans = max(ans, i);
		ans = n - ans;
		int p = n;
		for(int i = n; i > 1; i--) if(a[i] <= n && a[i] == a[i - 1]){
			ans++;
			p = min(p, (a[i] - 1) / 2);
			while(p > 0 && vis[p]) p--;
			if(p == 0) break;
			vis[p] = true;
		}
		if(p == 0){
			puts("-1");
			continue;
		}
		p = n;
		while(p > 0 && vis[p]) p--;
		for(int i = n; i > 0 && a[i] > n; i--){
			if((a[i] - 1) / 2 < p)
				break;
			do p--; while(p > 0 && vis[p]);
		}
		printf("%d\n", p == 0 ? ans : -1);
	}
	return 0;
}