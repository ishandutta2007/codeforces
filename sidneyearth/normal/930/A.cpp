#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int cnt[maxn], deep[maxn];
int main(){
	int n; scanf("%d", &n);
	cnt[1] = deep[1] = 1;
	for(int i = 2; i <= n; i++){
		int p; scanf("%d", &p);
		deep[i] = deep[p] + 1;
		cnt[deep[i]] ^= 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += cnt[i];
	printf("%d\n", ans);
	return 0;
}