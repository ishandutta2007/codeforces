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

const int N=2000000+19;

struct QType{
	int x,l,r,f,id;
	bool operator < (const QType &B) const{
		return x<B.x;
	}
} Q[N];

int p[N],id[N],sum[N],val[N];
int l,r,u,d,n,q,num,qc,c;
ll ans[N],res;

void Add(int x){
	for (;x<=n;x+=x&-x) sum[x]++;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=sum[x];
	return res;
}

int main(){
	n=IN();q=IN();
	For(i,1,n+1) p[IN()]=i;
	For(i,1,q+1){
		l=IN(),u=IN(),r=IN(),d=IN();
		res=1ll*n*(n-1)/2;
		res-=1ll*(u-1)*(u-2)/2;
		res-=1ll*(n-d)*(n-d-1)/2;
		res-=1ll*(l-1)*(l-2)/2;
		res-=1ll*(n-r)*(n-r-1)/2;
		ans[i]=res;
		id[++num]=i;
		Q[++qc]=(QType){u-1,1,l-1,1,num};
		id[++num]=i;
		Q[++qc]=(QType){u-1,r+1,n,1,num};
		id[++num]=i;
		Q[++qc]=(QType){n,1,l-1,1,num};
		Q[++qc]=(QType){d,1,l-1,-1,num};
		id[++num]=i;
		Q[++qc]=(QType){n,r+1,n,1,num};
		Q[++qc]=(QType){d,r+1,n,-1,num};
	}
	sort(Q+1,Q+qc+1);
	c=1;
	for (;c<=qc&&Q[c].x==0;c++);
	For(i,1,n+1){
		Add(p[i]);
		for (;c<=qc&&Q[c].x==i;c++){
			val[Q[c].id]+=Q[c].f*(Qry(Q[c].r)-Qry(Q[c].l-1));
		}
	}
	For(i,1,num+1){
		ans[id[i]]+=1ll*val[i]*(val[i]-1)/2;
	}
	For(i,1,q+1) printf("%I64d\n",ans[i]);
}