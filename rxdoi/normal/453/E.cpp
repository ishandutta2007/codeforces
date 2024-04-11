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
const int Top=10000000;
const int top=1e9;
const int oo=(1<<30)-1;

struct node *null;
struct node{
	node *L,*R;
	ll sum;
} Nd[Top],*cur=Nd+1,*rtA[N],*rtB[N];
int Qx,Qv,Ql,Qr;

node *New(node *L,node *R,ll sum){
	return *cur=(node){L,R,sum},cur++;
}
node *Modify(node *x,int L,int R){
	if (L==R) return New(0x0,0x0,x->sum+Qv);
	if (Qx<=Mid){
		return New(Modify(x->L,L,Mid),x->R,x->sum+Qv);
	} else{
		return New(x->L,Modify(x->R,Mid+1,R),x->sum+Qv);
	}
}
ll Query(node *x,int L,int R){
	if (x==null) return 0;
	if (Ql<=L&&R<=Qr) return x->sum;
	ll res=0;
	if (Ql<=Mid) res+=Query(x->L,L,Mid);
	if (Qr>Mid) res+=Query(x->R,Mid+1,R);
	return res;
}
ll Query(int L,int R,int T){
	ll res;
	Ql=T,Qr=top;
	res=T*(Query(rtA[R],0,top)-Query(rtA[L-1],0,top));
	Ql=0,Qr=T-1;
	if (Ql<=Qr) res+=Query(rtB[R],0,top)-Query(rtB[L-1],0,top);
	return res;
}

struct Info{
	int l,r,las;
	bool operator < (const Info &B) const{
		if (l!=B.l) return l<B.l;
		if (r!=B.r) return r<B.r;
		return las<B.las;
	}
};
set<Info> S;
int s[N],m[N],r[N],vis[N];
int n,q,T,L,R;
ll res;

int main(){
	null=Nd;
	*null=(node){null,null,0};
	For(i,0,N){
		rtA[i]=rtB[i]=null;
	}
	n=IN();
	For(i,1,n+1){
		s[i]=IN();m[i]=IN();r[i]=IN();
		rtA[i]=rtA[i-1];
		rtB[i]=rtB[i-1];
		if (r[i]){
			Qx=m[i]/r[i];
			Qv=r[i];rtA[i]=Modify(rtA[i],0,top);
			Qv=m[i];rtB[i]=Modify(rtB[i],0,top);
		}
		S.insert((Info){i,i,-1});
	}
	S.insert((Info){oo,oo,0});
	for (int q=IN();q--;){
		T=IN(),L=IN(),R=IN();
		Info A=*--S.upper_bound((Info){L,oo,0});
		if (A.l!=L){
			S.erase(A);
			S.insert((Info){A.l,L-1,A.las});
			S.insert((Info){L,A.r,A.las});
		}
		Info B=*--S.upper_bound((Info){R,oo,0});
		if (B.r!=R){
			S.erase(B);
			S.insert((Info){B.l,R,B.las});
			S.insert((Info){R+1,B.r,B.las});
		}
		res=0;
		for (;;){
			Info C=*S.lower_bound((Info){L,0,0});
			if (C.l>R) break;
			S.erase(C);
			if (C.l==C.r&&!vis[C.l]){
				vis[C.l]=1;
				res+=min(s[C.l]+1ll*r[C.l]*T,0ll+m[C.l]);
			} else{
				res+=Query(C.l,C.r,T-C.las);
			}
		}
		S.insert((Info){L,R,T});
		/*
		for (Info A:S){
			printf("	[%d,%d]:%d\n",A.l,A.r,A.las);
		}
		*/
		printf("%I64d\n",res);
	}
}