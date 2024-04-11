#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int vis[maxn];
int main(){
	int n; scanf("%d", &n);
	int ans = 0, cnt = 0;
	for(int i = 0; i < 2 * n; i++){
		int t; scanf("%d", &t);
		if(!vis[t]) cnt++;
		else cnt--;
		vis[t] = true;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}