#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=500;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,k;
char s[Maxn+5][Maxn+5];
int sum[Maxn+5][Maxn+5];
int find_id(int x,int y){
	return (x-1)*n+y;
}
int num[Maxn*Maxn+5];
namespace DSU{
	int fa[Maxn*Maxn+5],sz[Maxn*Maxn+5];
	void init(){
		for(int i=1;i<=n*n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		sz[fa_x]+=sz[fa_y];
		fa[fa_y]=fa_x;
	}
}
int val;
void add(int x,int y){
	if(x<1||y<1||x>n||y>n||s[x][y]=='X'){
		return;
	}
	x=find_id(x,y);
	x=DSU::find(x);
	if(num[x]==0){
		val+=DSU::sz[x];
	}
	num[x]++;
}
void del(int x,int y){
	if(x<1||y<1||x>n||y>n||s[x][y]=='X'){
		return;
	}
	x=find_id(x,y);
	x=DSU::find(x);
	num[x]--;
	if(num[x]==0){
		val-=DSU::sz[x];
	}
}
int find_sum(int x_1,int y_1,int x_2,int y_2){
	return sum[x_2][y_2]-sum[x_1-1][y_2]-sum[x_2][y_1-1]+sum[x_1-1][y_1-1];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(s[i][j]=='X'){
				sum[i][j]++;
			}
		}
	}
	DSU::init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='X'){
				continue;
			}
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(nx<1||ny<1||nx>n||ny>n||s[nx][ny]=='X'){
					continue;
				}
				DSU::merge(find_id(i,j),find_id(nx,ny));
			}
		}
	}
	int x=1,y=1;
	int p=1;
	int ans=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			add(i,j);
		}
	}
	while(x<=n-k+1){
		for(int i=1;i<=k;i++){
			add(x-1,y+i-1);
			add(x+k,y+i-1);
			add(x+i-1,y-1);
			add(x+i-1,y+k);
		}
		ans=max(ans,val+find_sum(x,y,x+k-1,y+k-1));
		for(int i=1;i<=k;i++){
			del(x-1,y+i-1);
			del(x+k,y+i-1);
			del(x+i-1,y-1);
			del(x+i-1,y+k);
		}
		y+=p;
		if(y<1){
			y=1;
			x++;
			if(x>n-k+1){
				break;
			}
			for(int i=1;i<=k;i++){
				del(x-1,y+i-1);
				add(x+k-1,y+i-1);
			}
			p=-p;
		}
		else if(y>n-k+1){
			y=n-k+1;
			x++;
			if(x>n-k+1){
				break;
			}
			for(int i=1;i<=k;i++){
				del(x-1,y+i-1);
				add(x+k-1,y+i-1);
			}
			p=-p;
		}
		else{
			for(int i=1;i<=k;i++){
				if(p==1){
					del(x+i-1,y-1);
					add(x+i-1,y+k-1);
				}
				else{
					del(x+i-1,y+k);
					add(x+i-1,y);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}