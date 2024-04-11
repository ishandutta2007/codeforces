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
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=40000+19;
const int M=1000+19;
const int p=1e7+19;
const int q=1e9+7;

int w[N],v[N],s[N],t[N],Q[N],f[M];
int n,m,Qc,num;

vector<pii> V[N*4];
int Ql,Qr;
pii Qv;
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		V[x].pb(Qv);
		return;
	}
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
}
void Work(int x,int L,int R,int *g){
	int f[N];
	memcpy(f,g,sizeof(int)*M);
	For(i,0,V[x].size()){
		int v=V[x][i].fi,w=V[x][i].se;
		for (int j=m;j>=w;j--) f[j]=max(f[j],f[j-w]+v);
	}
	if (L==R){
		if (Q[L]){
			int res=0;
			for (int i=m;i;i--){
				res=(1ll*res*p+f[i])%q;
			}
			printf("%d\n",res);
		}
		return;
	}
	Work(Lsn,L,Mid,f);
	Work(Rsn,Mid+1,R,f);
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1){
		v[i]=IN(),w[i]=IN();
	}
	Qc=IN();
	For(i,1,N){
		s[i]=1,t[i]=Qc;
	}
	num=n;
	For(i,1,Qc+1){
		int o=IN();
		if (o==1){
			num++;
			v[num]=IN(),w[num]=IN();
			s[num]=i;t[num]=Qc;
		}
		if (o==2){
			t[IN()]=i;
		}
		if (o==3){
			Q[i]=1;
		}
	}
	For(i,1,num+1){
		Ql=s[i],Qr=t[i];
		Qv=mp(v[i],w[i]);
		Modify(1,1,Qc);
	}
	Work(1,1,Qc,f);
}