#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int cnt;
int mat[20010][266];
int id[110][110];
int ans[310];
int sub(int x,int y){
	return (x%3-y%3+3)%3;
}
int add(int x,int y){
	return (x%3+y%3)%3;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		memset(id,0,sizeof(id));
		for(int i=1;i<=m;++i){
			int u=read(),v=read(),c=read();
			id[u][v]=id[v][u]=i;
			if(c!=-1) ans[i]=c;
			else ans[i]=0;
		}
		cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=j+1;k<=n;++k) if(id[i][j]&&id[i][k]&&id[j][k]) {
					++cnt;memset(mat[cnt],0,sizeof(mat[cnt]));
					// printf("cnt:%d\n",cnt);
					if(ans[id[i][j]]==0) mat[cnt][id[i][j]]=1;
					else mat[cnt][m+1]=sub(mat[cnt][m+1],ans[id[i][j]]);
					if(ans[id[i][k]]==0) mat[cnt][id[i][k]]=1;
					else mat[cnt][m+1]=sub(mat[cnt][m+1],ans[id[i][k]]);
					if(ans[id[k][j]]==0) mat[cnt][id[j][k]]=1;
					else mat[cnt][m+1]=sub(mat[cnt][m+1],ans[id[j][k]]);
					// printf("%d %d %d %d\n",mat[cnt][1],mat[cnt][2],mat[cnt][3],mat[cnt][4]);
				}
			}
		}
		int p=1,i=0;
		for(i=1;i<=cnt&&p<=m;++i,++p){
			// printf("i:%d,p:%d\n",i,p);
			for(int j=i;j<=cnt;++j) if(mat[j][p]){
				swap(mat[i],mat[j]);break ;
			}
			if(!mat[i][p]){
				--i;continue ;
			}
			if(mat[i][p]==2) for(int j=1;j<=m+1;++j) mat[i][j]=sub(0,mat[i][j]);
			for(int j=i+1;j<=cnt;++j){
				if(mat[j][p]){
					bool f=(mat[j][p]==1);
					for(int k=p;k<=m+1;++k){
						mat[j][k]=(f?sub:add)(mat[j][k],mat[i][k]);
					}
				}
			}
		}
		bool fl=0;
		for(int j=i;j<=cnt;++j){
			if(mat[j][m+1]){
				fl=1;break ;
			}
		}
		if(fl){
			printf("-1\n");continue ;
		}
		// printf("i:%d\n",i);
		for(int j=i-1;j>0;--j){
			int p=0;
			for(int k=1;k<=m;++k){
				if(mat[j][k]%3){
					if(p){
						ans[k]=0;
						for(int l=1;l<=cnt;++l) mat[l][k]=0;
					}
					else p=k;
				}
			}
			ans[p]=mat[j][m+1]*mat[j][p]%3;
			for(int k=1;k<=j;++k){
				mat[k][m+1]=sub(mat[k][m+1],ans[p]*mat[k][p]);
				mat[k][p]=0;
			}
		}
		for(int i=1;i<=m;++i) printf("%d ",(ans[i]+3)%3==0?3:(ans[i]+3)%3);printf("\n");
	}
}