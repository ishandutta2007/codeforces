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

const int N=100000+19;

int mx[N*4];
ll sum[N*4];
int Ql,Qr,Qx,Qv,pos;

int val[N];
int n,Qc,v;

inline int cmp(int x,int y) {return val[x]>val[y]?x:y;}

void Build(int x,int L,int R){
	if (L==R){
		mx[x]=L;
		sum[x]=val[L];
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	mx[x]=cmp(mx[Lsn],mx[Rsn]);
	sum[x]=sum[Lsn]+sum[Rsn];
}
void Modify(int x,int L,int R){
	if (L==R){
		mx[x]=L;
		sum[x]=Qv;
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	mx[x]=cmp(mx[Lsn],mx[Rsn]);
	sum[x]=sum[Lsn]+sum[Rsn];
}
ll Qsum(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x];
	ll res=0;
	if (Ql<=Mid) res+=Qsum(Lsn,L,Mid);
	if (Qr>Mid) res+=Qsum(Rsn,Mid+1,R);
	return res;
}
int Qmax(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return mx[x];
	int res=0;
	if (Ql<=Mid) res=cmp(res,Qmax(Lsn,L,Mid));
	if (Qr>Mid) res=cmp(res,Qmax(Rsn,Mid+1,R));
	return res;
}

int main(){
	n=IN();Qc=IN();
	For(i,1,n+1) val[i]=IN();
	Build(1,1,n);
	while (Qc--){
		int o=IN();
		if (o==1){
			Ql=IN(),Qr=IN();
			printf("%I64d\n",Qsum(1,1,n));
		}
		if (o==2){
			Ql=IN(),Qr=IN(),v=IN();
			while (val[pos=Qmax(1,1,n)]>=v){
				Qx=pos;Qv=val[pos]%v;
				val[pos]=Qv;
				Modify(1,1,n);
			}
		}
		if (o==3){
			Qx=IN(),Qv=IN();
			val[Qx]=Qv;
			Modify(1,1,n);
		}
	}
}