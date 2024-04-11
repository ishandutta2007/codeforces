#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int n, k, x[N], y[N];
int pre[N], suf[N];
int query(int c) {
	return upper_bound(x + 1, x + 1 + n, c) - x - 1;
}
int query2(int c) {
	int pos = lower_bound(x + 1, x + 1 + n, c) - x; 
	return n - pos + 1;
}
int main() {
	scanf("%d", &t);
	while (t--){

		scanf("%d%d", &n, &k);
		for(int i=0;i<=n+1;i++)pre[i]=suf[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&y[i]);
		}
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			pre[i] = query(x[i]) - query(x[i] - k - 1);
			suf[i] = query2(x[i]) - query2(x[i] + k + 1);
		}
		for(int i=2;i<=n;i++)
			pre[i]=max(pre[i-1],pre[i]);
		for(int i=n-1;i>=1;i--)
			suf[i]=max(suf[i+1],suf[i]);
		
		int ans=0;
		for(int i=0;i<=n;i++){
			//printf("pre[%d]=%d, %d\n", i,pre[i],suf[i]);
			if(x[i]==x[i+1])continue;
			ans=max(ans,pre[i]+suf[i+1]);
		}
		printf("%d\n", ans);
	}
}