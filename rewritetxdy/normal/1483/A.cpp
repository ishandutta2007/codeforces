#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,m,num,cnt[N],c[N][10],ans[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		num = 0;
		for(int i=1;i <= m;i++){
			int k;
			scanf("%d",&k); c[i][0] = min(k,2);
			for(int j=1;j <= k;j++){
				scanf("%d",&c[i][2]);
				if(!c[i][1]){
					c[i][1] = c[i][2];
					ans[i] = c[i][1];
					cnt[c[i][1]]++;
					if(cnt[c[i][1]] > (m+1)/2) num = c[i][1];
				}
			}
		}
		if(num){
			for(int i=1;i <= m;i++) if(c[i][0] > 1 && c[i][1] == num){
				ans[i] = c[i][2];
				if(--cnt[num] <= (m+1)/2) break;
			}
		}
		if(cnt[num] > (m+1)/2) puts("NO");
		else{
			puts("YES");
			for(int i=1;i <= m;i++) printf("%d ",ans[i]);
			puts("");
		}
		for(int i=1;i <= n;i++) cnt[i] = 0;
		for(int i=1;i <= m;i++) c[i][1] = 0;
	}
}