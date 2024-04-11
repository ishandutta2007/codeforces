#include<bits/stdc++.h>
using namespace std;
int r[1005],c[1005],must[1005][1005],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&r[i]);
		for(int j=1;j<=r[i];++j)
			must[i][j]=1;
		must[i][r[i]+1]=-1;
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=c[i];++j){
			if(must[j][i]==-1){
				puts("0");
			//	cout<<j<<" "<<i<<endl;
				return 0;
			}
			must[j][i]=1;
		}
		if(must[c[i]+1][i]==1){puts("0");return 0;}
		must[c[i]+1][i]=-1;
	}
	int res=1,Mod=1000000007;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!must[i][j])res=res*2%Mod;
	printf("%d",res);
	return 0;
}