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
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if ((y=E[i].y)!=fa)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

struct Edge{
	int y,z,nxt;
} E[N*2];
int las[N],F[N],G[N],pro[N];
int n,cnt,x,y,z;

void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void dp(int x,int fa,int val){
	int a=(x==1?0:1);
	Rep(x){
		dp(y,x,E[i].z);
		a++;
	}
	if (a==1){
		pro[x]=F[x]=G[x]=0;
		return;
	}
	//pro
	if (x==1){
		pro[x]=0;
	} else{
		int cp=a;
		Rep(x){
			cp=(cp-pro[y]+p)%p;
		}
		pro[x]=Pow(cp,p-2);
	}
	//F
	int sf=(x==1?0:val),cf=a;
	Rep(x){
		sf=(sf+1ll*(F[y]+1ll*pro[y]*E[i].z)%p*pro[x])%p;
		cf=(cf-pro[y]+p)%p;
	}
	F[x]=1ll*sf*Pow(cf,p-2)%p;
	//G
	int sg=0,cg=a;
	Rep(x){
		sg=(sg+G[y]+1ll*E[i].z*(1-pro[y]+p)+1ll*(F[y]+1ll*pro[y]*E[i].z)%p*(1-pro[x]+p))%p;
		cg=(cg-pro[y]+p)%p;
	}
	G[x]=1ll*sg*Pow(cg,p-2)%p;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n){
		x=IN()+1,y=IN()+1,z=IN();
		Link(x,y,z);
	}
	dp(1,-1,0);
	printf("%d\n",G[1]);
}