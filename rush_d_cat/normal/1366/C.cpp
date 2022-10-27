#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 102;
int t,n,m;
int a[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int cnt[N]={0},one[N]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				int tot=n+m-2;
				int now=i+j-2;
				int tmp=min(now,tot-now);
				if(now+now==tot)continue;
				cnt[tmp]++;
				if(a[i][j]) one[tmp]++;
			}
		}
		int ans=0;
		for(int i=0;i<N;i++){
			ans+=min(one[i],cnt[i]-one[i]);
		}
		printf("%d\n", ans);
	}
}