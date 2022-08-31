#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
map<int,int>ls;
int fa[MAXN];int tot=0;int L[MAXN],R[MAXN];
vector<int>sum[MAXN*4];
int n,m;int tmp[MAXN*4];
int jdb[MAXN][3];
int get(int x){return (x==fa[x]?x:fa[x]=get(fa[x]));}
inline void Union(int a,int b){a=get(a);b=get(b);fa[b]=a;L[a]=min(L[a],L[b]);R[a]=max(R[a],R[b]);}
void Do(int now,int l,int r,int x,int v){
	if(sum[now].size()){
		while(sum[now].size()){
			int u=sum[now][sum[now].size()-1];
			Union(u,v);sum[now].pop_back();
		}
		vector<int>().swap(sum[now]);
		sum[now].push_back(v);
	}
	if(l==r)return;int mid=(l+r)>>1;
	if(x<=mid)Do(now*2,l,mid,x,v);
	if(x>mid)Do(now*2+1,mid+1,r,x,v);
}
void Add(int now,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		sum[now].push_back(v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)Add(now*2,l,mid,x,y,v);
	if(y>mid)Add(now*2+1,mid+1,r,x,y,v);
}
int main(){
	scanf("%d",&m);
	rep(i,1,m){
		rep(j,0,2)scanf("%d",&jdb[i][j]);
		if(jdb[i][0]==1){
			tmp[++tmp[0]]=jdb[i][1];
			tmp[++tmp[0]]=jdb[i][2];
		}
	}
	sort(tmp+1,tmp+1+tmp[0]);int number=0;
	rep(i,1,tmp[0])if(i==1||tmp[i]!=tmp[i-1])ls[tmp[i]]=++tot;
	rep(i,1,m)if(jdb[i][0]==1){jdb[i][1]=ls[jdb[i][1]];jdb[i][2]=ls[jdb[i][2]];}
	rep(i,1,m){
		if(jdb[i][0]==1){
			L[++number]=jdb[i][1];
			R[number]=jdb[i][2];
			fa[number]=number;
			Do(1,1,tot,jdb[i][1],number);
			Do(1,1,tot,jdb[i][2],number);
			if(jdb[i][1]+1<=jdb[i][2]-1)Add(1,1,tot,jdb[i][1]+1,jdb[i][2]-1,number);
		}
		else{
			jdb[i][2]=get(jdb[i][2]);
			if(L[jdb[i][1]]>=L[jdb[i][2]]&&R[jdb[i][1]]<=R[jdb[i][2]])printf("YES\n");
			else printf("NO\n");
		}
	}
}