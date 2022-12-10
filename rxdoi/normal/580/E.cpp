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

int n,Q,Ql,Qr,Qv,l,r,d;
char s[N];

struct SegTree{
	int B,p;
	int sum[N*4],cov[N*4];
	int pw[N],inv[N],A[N];
	int Pow(int a,int b){
		int res=1;
		for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
		return res;
	}
	void Build(int x,int L,int R){
		cov[x]=-1;
		if (L==R){
			sum[x]=1ll*(s[L]-'0')*pw[L]%p;
			return;
		}
		Build(Lsn,L,Mid);
		Build(Rsn,Mid+1,R);
		sum[x]=(sum[Lsn]+sum[Rsn])%p;
	}
	void Cover(int x,int L,int R,int v){
		sum[x]=1ll*v*(A[R]-A[L-1]+p)%p;
		cov[x]=v;
	}
	void Down(int x,int L,int R){
		if (~cov[x]){
			Cover(Lsn,L,Mid,cov[x]);
			Cover(Rsn,Mid+1,R,cov[x]);
			cov[x]=-1;
		}
	}
	void Modify(int x,int L,int R){
		if (Ql<=L&&R<=Qr){
			Cover(x,L,R,Qv);
			return;
		}
		Down(x,L,R);
		if (Ql<=Mid) Modify(Lsn,L,Mid);
		if (Qr>Mid) Modify(Rsn,Mid+1,R);
		sum[x]=(sum[Lsn]+sum[Rsn])%p;
	}
	int Query(int x,int L,int R){
		if (Ql<=L&&R<=Qr) return sum[x];
		Down(x,L,R);
		int res=0;
		if (Ql<=Mid) res+=Query(Lsn,L,Mid);
		if (Qr>Mid) res+=Query(Rsn,Mid+1,R);
		return res%p;
	}
	int Hash(int l,int r){
		Ql=l,Qr=r;
		return l>r?0:1ll*Query(1,1,n)*inv[l]%p;
	}
	void Init(int __B,int __p){
		B=__B;
		p=__p;
		pw[0]=1;
		For(i,1,n+1) pw[i]=1ll*B*pw[i-1]%p;
		inv[n]=Pow(pw[n],p-2);
		for (int i=n;i;i--) inv[i-1]=1ll*B*inv[i]%p;
		For(i,1,n+1) A[i]=(A[i-1]+pw[i])%p;
		Build(1,1,n);
	}
} S1,S2;

int main(){
	n=IN(),Q=IN()+IN();
	scanf("%s",s+1);
	S1.Init(23,1e9+7);
	S2.Init(17,2333333);
	while (Q--){
		if (IN()==1){
			Ql=IN(),Qr=IN(),Qv=IN();
			S1.Modify(1,1,n);
			S2.Modify(1,1,n);
		} else{
			l=IN(),r=IN(),d=IN();
			if (S1.Hash(l,r-d)==S1.Hash(l+d,r)&&
				S2.Hash(l,r-d)==S2.Hash(l+d,r)) puts("YES");else puts("NO");
		}
	}
}