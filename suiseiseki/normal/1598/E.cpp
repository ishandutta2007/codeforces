#include <cstdio>
#include <algorithm>
const int Maxn=1000;
int n,m,q,ans;
bool a[Maxn+5][Maxn+5];
int query(int x,int y,int d_x,int d_y){
	if(a[x][y]){
		return 0;
	}
	int ans=1;
	while(1){
		x+=d_x,y+=d_y;
		std::swap(d_x,d_y);
		if(a[x][y]||x<1||x>n||y<1||y>m){
			break;
		}
		ans++;
	}
	return ans;
}
int f_l[Maxn+5][Maxn+5],f_u[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f_l[i][j]=f_u[i][j-1]+1;
			f_u[i][j]=f_l[i-1][j]+1;
			ans+=f_l[i][j]+f_u[i][j]-1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(a[x][y]){
			a[x][y]=0;
			int tmp=query(x,y,-1,0)*query(x,y,0,1)+query(x,y,0,-1)*query(x,y,1,0)-1;
			ans+=tmp;
		}
		else{
			int tmp=query(x,y,-1,0)*query(x,y,0,1)+query(x,y,0,-1)*query(x,y,1,0)-1;
			ans-=tmp;
			a[x][y]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}