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
#define Mid ((L+R)>>1)

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

const int N=500000+19;
const int top=500000;
const int oo=(1<<30)-1;

int sum[N*8],mn1[N*8],mn2[N*8];
int n,Qx,Ql,Qr,res;

void Build(int x,int L,int R){
	mn1[x]=oo;
	mn2[x]=oo;
	if (L==R) return;
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
}
void Modify(int x,int L,int R){
	if (L==R){
		sum[x]++;
		mn1[x]=L+1;
		mn2[x]=L-sum[x];
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
	mn1[x]=min(mn1[Lsn],mn1[Rsn]+sum[Lsn]);
	mn2[x]=min(mn2[Lsn],mn2[Rsn]-sum[Lsn]);
}
int Qsum(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x];
	int res=0;
	if (Ql<=Mid) res+=Qsum(Lsn,L,Mid);
	if (Qr>Mid) res+=Qsum(Rsn,Mid+1,R);
	return res;
}
int Qry1(int x,int L,int R,int plu){
	if (L==R){
		return min(-L,plu+sum[x]);
	}
	if (plu+mn1[Rsn]+sum[Lsn]<=0){
		return Qry1(Rsn,Mid+1,R,plu+sum[Lsn]);
	} else{
		return Qry1(Lsn,L,Mid,plu);
	}
}
int Qry2(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return mn2[x];
	int res=oo;
	if (Ql<=Mid) res=min(res,Qry2(Lsn,L,Mid));
	if (Qr>Mid) res=min(res,Qry2(Rsn,Mid+1,R)-sum[Lsn]);
	return res;
}

int main(){
	n=IN();
	Build(1,-top,top);
	For(i,1,n+1){
		Qx=IN();
		Modify(1,-top,top);
		if (mn1[1]>0){
			Ql=1;
			Qr=top;
		} else{
			Ql=-Qry1(1,-top,top,0)+1;
			Qr=top;
		}
		int s=Qsum(1,-top,top);
		res=Ql-1+s;
		if (Ql<=Qr){
			res=min(res,Qry2(1,-top,top)+i);
		}
		printf("%d\n",res);
	}
}