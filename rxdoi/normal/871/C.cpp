#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

map<int,int> idx,idy;
int fa[N],sz[N],cnt[N],fac[N],inv[N];
int n,x,y,id,ans;

int C(int n,int m){
	if (n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y){
		fa[x]=y;
		sz[y]+=sz[x];
		cnt[y]+=cnt[x];
	}
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	For(i,0,N) fa[i]=i,sz[i]=1;
	n=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		if (!idx[x]) idx[x]=++id;
		if (!idy[y]) idy[y]=++id;
		Union(idx[x],idy[y]);
		cnt[getf(idx[x])]++;
	}
	ans=1;
	For(i,1,id+1) if (fa[i]==i){
		int tmp=0;
		For(j,0,cnt[i]+1){
			tmp=(tmp+C(sz[i],j))%p;
		}
		ans=1ll*ans*tmp%p;
	}
	printf("%d\n",ans);
}