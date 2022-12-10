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

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
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

const int N=100000+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,z,nxt;
} E[N*2];
map<int,int> M;
int las[N],sz[N],vis[N],pw10[N];
int n,cnt,p,inv10,tmp,mn,cen,fcen,x,y,z;
ll res;

void exgcd(int a,int b,int &x,int &y){
    if (!b){
        x=1;y=0;
		return;
    } else{
        exgcd(b,a%b,x,y);
        int t=x;x=y;y=t-(a/b)*y;
    }
}
void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void findcen(int x,int fa,int n){
	int tmp=0;sz[x]=1;
	Rep(x) if (y!=fa){
		findcen(y,x,n);
		sz[x]+=sz[y];
		tmp=max(tmp,sz[y]);
	}
	tmp=max(tmp,n-sz[x]);
	if (tmp<mn) mn=tmp,cen=x,fcen=fa;
}
void dfs_A(int x,int fa,int A,int inv){
	M[1ll*(p-A)*inv%p]++;
	Rep(x) if (y!=fa){
		dfs_A(y,x,(10ll*A+E[i].z)%p,1ll*inv*inv10%p);
	}
}
void dfs_B(int x,int fa,int B,int len,int f){
	res+=f*M[B];
	Rep(x) if (y!=fa){
		dfs_B(y,x,(B+1ll*pw10[len]*E[i].z)%p,len+1,f);
	}
}
void work(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	M.clear();
	dfs_A(x,-1,0,1);
	dfs_B(x,-1,0,0,1);
	res--;
	Rep(x){
		M.clear();
		dfs_A(y,-1,E[i].z%p,inv10);
		dfs_B(y,-1,E[i].z%p,1,-1);
	}
	Rep(x) work(y,sz[y]);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),p=IN();
	pw10[0]=1;
	For(i,1,N) pw10[i]=10ll*pw10[i-1]%p;
	exgcd(10,p,inv10,tmp);
	inv10=(inv10%p+p)%p;
	For(i,1,n){
		x=IN()+1,y=IN()+1,z=IN();
		Link(x,y,z);
	}
	work(1,n);
	printf("%I64d\n",res);
}