#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;
const int B = 400;

int n,m;
int lef[N],rig[N];
int fa[N];
int a[N];
bool vacation[N];
int S;
int key[N],k;
int ans[N];
int op[N];
int dfn[N],R[N];
int rmq[N*2][20],fir[N],nn;
int dep[N];

void dfs(int x){
	dfn[x]=++k;
	rmq[fir[x]=++nn][0]=x;
	for(int y=lef[x];y;y=rig[y]){
		dep[y]=dep[x]+1;
		dfs(y);
		rmq[++nn][0]=x;
	}
	R[x]=k;
}

void getrmq(){
	fo(j,1,log(nn)/log(2))
		fo(i,1,nn-(1<<j)+1)
		rmq[i][j]=dep[rmq[i][j-1]]<dep[rmq[i+(1<<(j-1))][j-1]]?rmq[i][j-1]:rmq[i+(1<<(j-1))][j-1];
}

int lca(int x,int y){
	x=fir[x],y=fir[y];
	if (x>y)swap(x,y);
	int t=log(y-x+1)/log(2);
	return dep[rmq[x][t]]<dep[rmq[y-(1<<t)+1][t]]?rmq[x][t]:rmq[y-(1<<t)+1][t];
}

int Fa[N];

bool cmp(int x,int y){return dfn[x]<dfn[y];}

int be[N],u;
int now;
int Lef[N],Rig[N];
int ad[N];
int cnt[B*2][B*2];

bool cmp1(int x,int y){return a[x]<a[y];}

int main(){
	n=get();m=get();
	fo(i,2,n){
		fa[i]=get();
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	fo(i,1,n)a[i]=get();
	fo(i,1,m)op[i]=abs(get());
	dfs(dep[1]=1);
	getrmq();
	S=sqrt(n)+1;
	now=0;
	fo(nd,1,(m-1)/S+1){
		int l=(nd-1)*S+1,r=min(m,nd*S);
		k=0;
		fo(i,l,r)key[++k]=op[i];
		sort(key+1,key+1+k,cmp);
		key[++k]=1;
		int k1=k;
		fo(i,1,k1-1)key[++k]=lca(key[i],key[i+1]);
		sort(key+1,key+1+k,cmp);
		k1=1;
		fo(i,2,k)if (key[i]!=key[i-1])key[++k1]=key[i];
		k=k1;
		fo(i,1,k)if (!vacation[key[i]]&&a[key[i]]<0)now--;
		fo(i,1,k)Fa[key[i]]=Lef[key[i]]=Rig[key[i]]=0;
		for(int i=2,y=1;i<=k;i++){
			int x=key[i];
			while(!(dfn[y]<=dfn[x]&&dfn[x]<=R[y]))y=Fa[y];
			Fa[x]=y;
			Rig[x]=Lef[y];
			Lef[y]=x;
			y=x;
		}
		fo(i,1,k)be[key[i]]=i;
		fo(i,1,k){
			int x=key[i];
			fo(j,0,S*2)cnt[i][j]=0;
			for(int y=x;y&&y!=Fa[x];y=fa[y]){
				if (y!=x&&!vacation[y]&&abs(a[y])<=S)cnt[i][S+a[y]]++;
			}
			ad[x]=0;
		}
		fo(i,l,r){
			int x=op[i];
			if (!vacation[x]){
				for(int y=x;y;y=Fa[y]){
					now=now+cnt[be[y]][S+ad[y]];
					ad[y]++;
					a[y]--;
				}
				vacation[x]=1;
			}
			else{
				for(int y=x;y;y=Fa[y]){
					ad[y]--;
					now=now-cnt[be[y]][S+ad[y]];
					a[y]++;
				}
				vacation[x]=0;
			}
			ans[i]=now;
			fo(u,1,k)
			if (!vacation[key[u]]&&a[key[u]]<0)ans[i]++;
		}
		fo(i,1,k){
			int x=key[i];
			for(int y=x;y&&y!=Fa[x];y=fa[y])
				if (y!=x)a[y]=a[y]-ad[x];
		}
		now=0;
		fo(i,1,n)if (!vacation[i]&&a[i]<0)now++;
	}
	fo(i,1,m)printf("%d ",ans[i]);
	return 0;
}