#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int M=1000+3;

struct Edge{
	int y,nxt;
} E[N*2];
int plu[N*4];
bitset<M> sum[N*4],pri,res,All;
int las[N],I[N],O[N],val[N],A[N];
int n,m,cnt,tot,x,v,Ql,Qr,Qv;

void Build(int x,int L,int R){
	if (L==R){
		sum[x][val[L]]=1;
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]|sum[Rsn];
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		plu[x]=(plu[x]+Qv)%m;
		sum[x]=(sum[x]<<Qv)|(sum[x]>>m-Qv);
		sum[x]&=All;
		return;
	}
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]|sum[Rsn];
	sum[x]=(sum[x]<<plu[x])|(sum[x]>>m-plu[x]);
	sum[x]&=All;
}
void Query(int x,int L,int R,int tmp){
	if (Ql<=L&&R<=Qr){
		res|=sum[x]<<tmp;
		res|=sum[x]>>m-tmp;
		return;
	}
	if (Ql<=Mid) Query(Lsn,L,Mid,(tmp+plu[x])%m);
	if (Qr>Mid) Query(Rsn,Mid+1,R,(tmp+plu[x])%m);
}

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	I[x]=++tot;
	val[tot]=A[x];
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
		}
	O[x]=tot;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n+1) A[i]=IN()%m;
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	Build(1,1,n);
	For(i,0,m) All[i]=1;
	For(i,2,m) pri[i]=1;
	for (int i=2;i<m;i++)
		if (pri[i]==1){
			for (int j=i+i;j<m;j+=i) pri[j]=0;
		}
	for (int q=IN();q--;)
		if (IN()==1){
			x=IN(),Qv=IN()%m;
			Ql=I[x],Qr=O[x];
			Modify(1,1,n);
		} else{
			x=IN();
			Ql=I[x],Qr=O[x];
			res.reset();
			Query(1,1,n,0);
			res&=pri;
			printf("%d\n",res.count());
		}
}