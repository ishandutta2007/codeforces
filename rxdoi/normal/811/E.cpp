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

const int N=100000+19;

int A[11][N];
int fa[50],id[50];
int n,m,q,Ql,Qr;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) return fa[x]=y,1;
	return 0;
}

struct node{
	int s[21];
	int sum;
} S[N*4];

node Update(node A,node B,int pos){
	static node tmp;
	For(i,1,4*n+1) fa[i]=i;
	tmp.sum=A.sum+B.sum;
	For(i,1,n+1){
		if (::A[i][pos]==::A[i][pos+1]){
			tmp.sum-=Union(A.s[i+n],B.s[i]+2*n);
		}
	}
	int cnt=0;
	memset(id,0,sizeof(id));
	For(i,1,n+1){
		int &u=id[getf(A.s[i])];
		if (!u) u=++cnt;
		tmp.s[i]=u;
	}
	For(i,1,n+1){
		int &u=id[getf(B.s[i+n]+2*n)];
		if (!u) u=++cnt;
		tmp.s[i+n]=u;
	}
	return tmp;
}
void Build(int x,int L,int R){
	if (L==R){
		int tmp=0;
		For(i,1,n+1){
			if (i==1||A[i][L]!=A[i-1][L]) tmp++;
			S[x].s[i]=S[x].s[i+n]=tmp;
		}
		S[x].sum=tmp;
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x]=Update(S[Lsn],S[Rsn],Mid);
}
node Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return S[x];
	if (Qr<=Mid) return Query(Lsn,L,Mid);
	if (Ql>Mid) return Query(Rsn,Mid+1,R);
	return Update(Query(Lsn,L,Mid),Query(Rsn,Mid+1,R),Mid);
}

int main(){
	n=IN(),m=IN(),q=IN();
	For(i,1,n+1) For(j,1,m+1) A[i][j]=IN();
	Build(1,1,m);
	while (q--){
		Ql=IN(),Qr=IN();
		printf("%d\n",Query(1,1,m).sum);
	}
}