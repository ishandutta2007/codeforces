#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,c[N],k,z,f[N][6];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&z,&n,&k);
		for(int i=1;i <= z;i++) scanf("%d",&c[i]);
		for(int i=0;i <= n;i++) for(int j=0;j <= k;j++) f[i][j] = 0;
		for(int i=0;i < n;i++)
			for(int j=0;j <= k;j++){
				int x = 1+i-j*2;
				if(x <= 0) continue;
				f[i+1][j] = max(f[i+1][j],f[i][j]+c[x+1]);
				if(j < k && x > 1)
					f[i+1][j+1] = max(f[i+1][j+1],f[i][j]+c[x-1]);
			}
		int ans = 0;
		for(int j=0;j <= k;j++) ans = max(ans,f[n][j]);
		printf("%d\n",ans+c[1]);
	}
}