#include <stdio.h>
#include <memory.h>
#define clr(u) memset(u,0,sizeof(u))

int main(){
//	freopen("a.in","r",stdin);
	int i,j,k;
	int ni,nj;
	char s[15][15];
	scanf("%d%d\n",&ni,&nj);

	for(i=0;i<ni;i++)scanf("%s", s[i]);

	bool vis[15][15];
	clr(vis);

	int ans=0;

	for(i=0;i<ni;i++){
		for(j=0;j<nj;j++)if(s[i][j]=='S')break;
		if(j==nj){
			for(j=0;j<nj;j++){
				if(!vis[i][j])ans++;
				vis[i][j]=1;
			}
		}
	}

	for(j=0;j<nj;j++){
		for(i=0;i<ni;i++)if(s[i][j]=='S')break;
		if(i==ni){
			for(i=0;i<ni;i++){
				if(!vis[i][j])ans++;
				vis[i][j]=1;
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}