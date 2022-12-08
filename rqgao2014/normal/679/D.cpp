#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

const int inf=10000;
const double eps=1e-9;
int n,m,d[405][405],du[405],vis[405],g[405][405],num[405];
double si[405],maxx[405];


inline void upt(double &x,double y){
	if(y>=x) x=y;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) d[i][j]=0; else d[i][j]=inf;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		d[x][y]=d[y][x]=1;
		du[x]++;du[y]++;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	double ans=0;
	for(int i=1;i<=n;i++){
		double mx=0,tmp=0;
		int tot=0;
		memset(num,0,sizeof(num));
		for(int j=1;j<=n;j++){
			int t=d[i][j];
			g[t][++num[t]]=j;
		}
		for(int j=0;j<=n;j++)
			if(num[j]==1) tmp+=1.0;
			else if(num[j]>1){
				for(int k=1;k<=n;k++) si[k]=0.0;
				tot=0;
				for(int tt=1;tt<=num[j];tt++){
					int k=g[j][tt];
					for(int l=1;l<=n;l++)
						if(d[k][l]==1) si[l]+=1.0/(double)du[k];
				}
				for(int k=1;k<=n;k++)
					if(si[k]>eps) vis[++tot]=k;
				double res=0.0;
				for(int k=1;k<=n;k++){
					double t=0.0;
					for(int l=1;l<=tot;l++)
						upt(maxx[d[k][vis[l]]],si[vis[l]]);
					for(int l=1;l<=tot;l++)
						t+=maxx[d[k][vis[l]]],maxx[d[k][vis[l]]]=0.0;
					res=max(res,t);
				}
				tmp+=max(1.0,res);
			}
		ans=max(ans,tmp);
	//	printf("%.9lf\n",tmp);
	}
	printf("%.12lf\n",ans/(double)n);
	return 0;
}