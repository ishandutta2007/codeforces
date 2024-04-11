#include<bits/stdc++.h>
const int N=7,M=1003;
using namespace std;
int n,m,no[M],nxt[N][M],ans,p[N],ls,ind[N],it;
bool del[M];
vector<int>uni[M];
struct pt{
	int x,y;
	inline void rd(){scanf("%d%d",&x,&y);}
}a[N],b[M];
bool cmp(int x,int y){
	return b[x].x?abs(b[x].x)<abs(b[y].x):
	abs(b[x].y)<abs(b[y].y);
}
bool dfs(int x){
	if(del[x])return 1;
	if(ls==n)return 0;
	int tp=p[ls++];
	for(int y=nxt[tp][x];~y;y=nxt[tp][y])
	if(!dfs(y))return 0;
	return del[ind[it++]=x]=1;
}
bool fl;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)a[i].rd();
	for(int i=0;i<m;i++)b[i].rd();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		b[j].x-=a[i].x,b[j].y-=a[i].y;
		for(int j=0;j<m;j++)
		for(int k=0;k<=j;k++)
		if((b[j].x*1ll*b[k].x>0||b[j].y*1ll*b[k].y>0)
		&&b[j].x*1ll*b[k].y==b[j].y*1ll*b[k].x){
			//cerr<<j<<" sim "<<k<<endl;
			uni[k].push_back(j);
			break;
		}
		//cerr<<i<<":::\n";
		for(int j=0;j<m;j++){
			sort(uni[j].begin(),uni[j].end(),cmp);
			ls=-1;
			for(int k:uni[j]){
				nxt[i][k]=ls,ls=k;
				//cerr<<"<<"<<k;
			}
			//if(uni[j].size())cerr<<endl;
			uni[j].clear();
		}
		for(int j=0;j<m;j++)
		b[j].x+=a[i].x,b[j].y+=a[i].y;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)p[j]=j;
		fl=0;
		do{
			ls=0,fl=dfs(i);
			for(;it;del[ind[--it]]=0);
		}
		while(next_permutation(p,p+n)&&!fl);
		ans+=fl;
	}
	printf("%d",ans);
}