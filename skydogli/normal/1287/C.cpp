#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[105],vis[105];
int cnt[2],f[105][105][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		vis[a[i]]=1;
	}
//	cnt[0]=n/2;
//	cnt[1]=(n+1)/2;
	for(int i=1;i<=n;++i)if(!vis[i])cnt[i&1]++;
	memset(f,0x3f,sizeof(f));
	int qwq=0;
	f[0][0][0]=0;
	for(int i=1;i<=n;++i){
		//if(a[i])continue;
		for(int j=0;j<=min(i-1,cnt[0]);++j)
			for(int op=0;op<2;++op){
				
			if(a[i-1]&&((a[i-1]&1)!=op))continue;
			int k=(i-1-j)-qwq;
		//	cerr<<"HI: "<<i<<" "<<j<<" : "<<f[i-1][j][op]<<endl;
			if((j<cnt[0]&&!a[i])||(a[i]&&(a[i]&1)==0))
				f[i][j+(!a[i])][0]=min(f[i][j+(!a[i])][0],f[i-1][j][op]+(op&&i!=1));
			if((k<cnt[1]&&!a[i])||((a[i]&1)==1))
				f[i][j][1]=min(f[i][j][1],f[i-1][j][op]+(!op&&i!=1));
		}
		if(a[i]) qwq++;
	}
	printf("%d\n",min(f[n][cnt[0]][0],f[n][cnt[0]][1]));
}