#include<set>
#include<map>
#include<ctime>
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
#include<functional>

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

const int N=150000+19;
const int oo=(1<<30)-1;

struct Info{
	int val,cnt;
	bool operator < (const Info &B) const {return cnt>B.cnt;}
};

struct node{
	Info I[7];
	int sz;
} S[N*4],res;

int cov[N*4];
int n,m,p,K,Ql,Qr,Qv;

void Ins(node &A,node &B){
	For(i,0,B.sz){
		int mn=oo,b=0;
		For(j,0,A.sz)
			if (A.I[j].val==B.I[i].val){
				A.I[j].cnt+=B.I[i].cnt;
				b=1;break;
			}
		if (b) continue;
		A.I[A.sz++]=B.I[i];
		if (A.sz<=K) continue;
		For(i,0,A.sz) mn=min(mn,A.I[i].cnt);
		For(i,0,A.sz) A.I[i].cnt-=mn;
		sort(A.I,A.I+A.sz);
		while (A.sz&&A.I[A.sz-1].cnt==0) A.sz--;
	}
}
void Build(int x,int L,int R){
	if (L==R){
		S[x].sz=1;
		S[x].I[0]=(Info){IN(),1};
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x].sz=0;
	Ins(S[x],S[Lsn]);
	Ins(S[x],S[Rsn]);
}
void Cover(int x,int L,int R,int v){
	S[x].sz=1;
	S[x].I[0]=(Info){v,R-L+1};
	cov[x]=v;
}
void Down(int x,int L,int R){
	if (cov[x]){
		Cover(Lsn,L,Mid,cov[x]);
		Cover(Rsn,Mid+1,R,cov[x]);
		cov[x]=0;
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
	S[x].sz=0;
	Ins(S[x],S[Lsn]);
	Ins(S[x],S[Rsn]);
}
void Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Ins(res,S[x]);
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
}

int main(){
	//freopen("count.in","r",stdin);
	//freopen("count.out","w",stdout);
	n=IN(),m=IN(),p=IN();
	K=100/p;
	Build(1,1,n);
	while (m--)
		if (IN()==1){
			Ql=IN(),Qr=IN(),Qv=IN();
			Modify(1,1,n);
		} else{
			Ql=IN(),Qr=IN();
			res.sz=0;
			Query(1,1,n);
			printf("%d ",res.sz);
			For(i,0,res.sz) printf("%d ",res.I[i].val);
			puts("");
		}
}