#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=500010;
struct node{
	int lc,rc;
	int add,len;
	long long sum;
	long long getsum(){
		return sum+(long long)add*len;
	}
}N[MAXN*2];
int LN;
int FL;
int belong[MAXN];
int length[MAXN];
int st[MAXN];
int fa[MAXN];
int sz[MAXN];
int nodeid[MAXN];
vector<int> V[MAXN];
int rk[MAXN];
bool cmp(const int &x,const int &y){
	return sz[x]>sz[y];
}
void dfs(int x){
	sz[x]=1;
	for(auto &&y:V[x]){
		rk[y]=rk[x]+1;
		dfs(y);
		sz[x]+=sz[y];
	}
}
void dfs(int x,int f){
	belong[x]=f;
	++length[f];
	sort(V[x].begin(),V[x].end(),cmp);
	for(int i=0;i<int(V[x].size());++i){
		if(i==0) dfs(V[x][i],f);
		else{
			st[++FL]=V[x][i];
			dfs(V[x][i],FL);
		}
	}
}
void build(int l,int r,int id){
	N[id].len=r-l+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	N[id].lc=++LN;
	build(l,mid,N[id].lc);
	N[id].rc=++LN;
	build(mid+1,r,N[id].rc);
}
void add(int l,int r,int ll,int rr,int x){
	if(l==ll&&r==rr){
		++N[x].add;
		return;
	}
	int mid=(l+r)>>1;
	if(rr<=mid) add(l,mid,ll,rr,N[x].lc);
	else if(mid<ll) add(mid+1,r,ll,rr,N[x].rc);
	else add(l,mid,ll,mid,N[x].lc),add(mid+1,r,mid+1,rr,N[x].rc);
	N[x].sum=N[N[x].lc].getsum()+N[N[x].rc].getsum();
}
long long sum(int l,int r,int ll,int rr,int x){
	if(l==ll&&r==rr){
		return N[x].getsum();
	}
	long long tmp=(long long)N[x].add*(rr-ll+1);
	int mid=(l+r)>>1;
	if(rr<=mid) return tmp+sum(l,mid,ll,rr,N[x].lc);
	else if(mid<ll) return tmp+sum(mid+1,r,ll,rr,N[x].rc);
	else return tmp+sum(l,mid,ll,mid,N[x].lc)+sum(mid+1,r,mid+1,rr,N[x].rc);
}
long long ans[MAXN];
int n;
int main(){
	LN=FL=0;
	int CEO=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",fa+i);
		if(fa[i]==0) CEO=i;
		else V[fa[i]].push_back(i);
	}
	dfs(CEO);
	st[1]=CEO;
	FL=1;
	dfs(CEO,1);
	for(int i=1;i<=FL;++i){
		nodeid[i]=++LN;
		build(1,length[i],LN);
	}
	vector<int> FV;
	for(int i=1;i<=n;++i) if(i!=CEO){
		FV.push_back(i);
	}
	sort(FV.begin(),FV.end(),[&](int x,int y){return rk[x]<rk[y];});
	for(int i=0,j=0;i<int(FV.size());){
		while(j<int(FV.size())&&rk[FV[j]]==rk[FV[i]]){
			int jj=fa[FV[j]];
			while(true){
				int kk=belong[jj];
				add(1,length[kk],1,rk[jj]+1-rk[st[kk]],nodeid[kk]);
				if(st[kk]==CEO) break;
				jj=fa[st[kk]];
			}
			++j;
		}
		while(i<j){
			int ii=fa[FV[i]];
			while(true){
				int kk=belong[ii];
				ans[FV[i]]+=sum(1,length[kk],1,rk[ii]+1-rk[st[kk]],nodeid[kk]);
				if(st[kk]==CEO) break;
				ii=fa[st[kk]];
			}
			++i;
		}
	}
	for(int i=1;i<=n;++i) printf("%I64d%c",ans[i],i==n?'\n':' ');
	return 0;
}