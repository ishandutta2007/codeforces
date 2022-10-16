#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=14;
const int Maxm=100;
const int Inf=0x3f3f3f3f;
int n,m;
struct Node_1{
	int x,y;
}a[Maxn+5];
struct Node_2{
	int x,y,t;
	friend bool operator <(Node_2 a,Node_2 b){
		return a.t<b.t;
	}
}b[Maxm+5];
template<typename Elem_1,typename Elem_2>
int find_dis(Elem_1 a,Elem_2 b){
	return std::abs(a.x-b.x)+std::abs(a.y-b.y);
}
int dis_1[Maxn+5][1<<Maxn|5],dis_2[Maxm+5][1<<Maxn|5];
int f[1<<Maxn|5][Maxm+5],g[1<<Maxn|5][Maxm+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].t);
	}
	std::sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			dis_1[i][j]=Inf;
			for(int k=1;k<=n;k++){
				if((j>>(k-1))&1){
					dis_1[i][j]=std::min(dis_1[i][j],find_dis(a[i],a[k]));
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(1<<n);j++){
			dis_2[i][j]=Inf;
			for(int k=1;k<=n;k++){
				if((j>>(k-1))&1){
					dis_2[i][j]=std::min(dis_2[i][j],find_dis(b[i],a[k]));
				}
			}
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		g[(1<<(i-1))][0]=0;
	}
	memset(f,-0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		f[0][i]=1;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=m;j>0;j--){
			g[i][j-1]=std::min(g[i][j-1],g[i][j]);
		}
		for(int j=0;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(dis_2[k][i]+g[i][j]<=b[k].t){
					f[i][k]=std::max(f[i][k],j+1);
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(b[j].t+std::min(dis_2[k][i],find_dis(b[j],b[k]))<=b[k].t){
					f[i][k]=std::max(f[i][k],f[i][j]+1);
				}
			}
		}
		for(int j=0;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(((i>>(k-1))&1)==0){
					g[i|(1<<(k-1))][j]=std::min(g[i|(1<<(k-1))][j],g[i][j]+dis_1[k][i]);
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(f[i][j]<0){
				continue;
			}
			for(int k=1;k<=n;k++){
				if(((i>>(k-1))&1)==0){
					g[i|(1<<(k-1))][f[i][j]]=std::min(g[i|(1<<(k-1))][f[i][j]],b[j].t+std::min(dis_1[k][i],find_dis(b[j],a[k])));
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=m;j++){
			ans=std::max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}