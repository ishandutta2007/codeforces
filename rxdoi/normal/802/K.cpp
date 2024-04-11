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
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if ((y=E[i].y)!=fa)

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

const int N=100000+19;

struct Edge{
	int y,z,nxt;
} E[N*2];
pii tmp[N];
int las[N],F[N],G[N];
int n,K,x,y,z,cnt,tot;

void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void dp(int x,int fa){
	Rep(x) dp(y,x);
	tot=0;
	Rep(x) tmp[++tot]=mp(-F[y]-E[i].z,-G[y]-E[i].z);
	sort(tmp+1,tmp+tot+1);
	For(i,1,tot+1) tmp[i].fi+=tmp[i-1].fi;
	F[x]=-tmp[min(K-1,tot)].fi;
	For(i,1,tot+1){
		if (i<=K-1){
			G[x]=max(G[x],-(tmp[i].se+tmp[min(K,tot)].fi-tmp[i].fi+tmp[i-1].fi));
		} else{
			G[x]=max(G[x],-(tmp[i].se+tmp[K-1].fi));
		}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),K=IN();
	For(i,1,n){
		x=IN()+1,y=IN()+1,z=IN();
		Link(x,y,z);
	}
	dp(1,-1);
	printf("%d\n",G[1]);
}