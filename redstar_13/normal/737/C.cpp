#include <bits/stdc++.h>

using namespace std;
#define NN 200010
int a[NN];
int cnt[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,s;
	scanf("%d%d",&n,&s);
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i==s&&x) ans++;
		if(i!=s) cnt[x]++;
	}
	if(n==1){
		printf("%d\n",ans);
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum+=cnt[i];
		if(cnt[i]==0){
			ans++;
			sum++;
		}
		if(sum>=n) break;
	}
	printf("%d\n",ans);
    return 0;
}