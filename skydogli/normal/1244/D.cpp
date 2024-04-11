#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 100005
int n,co[3][MN],u,v,id[MN],col[MN];
LL f[MN][3][3];
vector<int>edge[MN];
void dfs(int x,int fa,int dep){
	id[dep]=x;
//	cout<<dep<<": "<<id[dep]<<endl;
	if(edge[x].size()>2){
		puts("-1");
		exit(0);
	}
	for(int i=0;i<edge[x].size();++i){
		if(edge[x][i]!=fa) dfs(edge[x][i],x,dep+1);
	}
}
struct data{
	int id,col1,col2;
	data(int ID=0,int COL1=0,int COL2=0){
		id=ID;col1=COL1;col2=COL2;
	}
}lead[MN][3][3];
void dfs(data w){
	col[id[w.id]]=w.col1;
//	cout<<"? "<<w.id<<" "<<w.col1<<" "<<w.col2<<endl;
	if(w.id==1)return;
	dfs(lead[w.id][w.col1][w.col2]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<3;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&co[i][j]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int rt=0;
	for(int i=1;i<=n;++i)
		if(edge[i].size()==1) rt=i;
	if(!rt){
		puts("-1");
		return 0;
	}
	dfs(rt,0,1);
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(i!=j){
			f[2][j][i]=(LL)co[i][id[1]]+co[j][id[2]];
			lead[2][j][i]=data(1,i,0);
		}
	for(int i=3;i<=n;++i){
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				if(j!=k)
				for(int l=0;l<3;++l)
					if(j!=k&&k!=l&&j!=l){
						if(f[i][j][k]>f[i-1][k][l]+(LL)co[j][id[i]]){
						//	cout<<"HI "<<endl;
							f[i][j][k]=f[i-1][k][l]+(LL)co[j][id[i]];
							lead[i][j][k]=data(i-1,k,l);
						}
					}
	}
	LL ans=1e18;
	data ANS;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(i!=j){
			if(ans>f[n][i][j]){
				ans=f[n][i][j];
				ANS=data(n,i,j);
			}	
		}
	printf("%I64d\n",ans);
	dfs(ANS);
	for(int i=1;i<=n;++i)printf("%d ",col[i]+1);
	return 0;
}