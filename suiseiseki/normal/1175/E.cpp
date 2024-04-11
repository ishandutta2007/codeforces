#include <cstdio>
#include <algorithm>
const int Maxn=200000;
const int Maxl=500000;
int n,m;
int mx_val[Maxl+5];
int fa[Maxl+5][20];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int l,r;	
		scanf("%d%d",&l,&r);
		mx_val[l]=std::max(mx_val[l],r);
	}
	for(int i=1;i<=Maxl;i++){
		mx_val[i]=std::max(mx_val[i-1],mx_val[i]);
	}
	for(int i=Maxl;i>=0;i--){
		fa[i][0]=(mx_val[i]<=i?0:mx_val[i]);
		for(int j=1;j<20;j++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=0;
		for(int j=19;j>=0;j--){
			if(fa[x][j]==0||fa[x][j]>=y){
				continue;
			}
			x=fa[x][j];
			ans+=(1<<j);
		}
		ans++;
		x=fa[x][0];
		if(x<y){
			puts("-1");
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}