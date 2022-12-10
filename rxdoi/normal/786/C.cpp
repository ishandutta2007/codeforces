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
const int Top=20000000;

struct node *null;
struct node{
	node *L,*R;
	int sum;
} Nd[Top],*rt[N],*cur=Nd+1;
int las[N],A[N];
int n,Ql,Qr,Qx,res,K;

node *Modify(node *x,int L,int R,int Qx,int Qv){
	node *y=cur++;
	*y=*x;
	y->sum+=Qv;
	if (L==R) return y;
	if (Qx<=Mid) y->L=Modify(x->L,L,Mid,Qx,Qv);
	if (Qx>Mid) y->R=Modify(x->R,Mid+1,R,Qx,Qv);
	return y;
}
int Query(node *x,int L,int R,int K){
	if (L==R) return L;
	if (x->L->sum>K){
		return Query(x->L,L,Mid,K);
	} else{
		return Query(x->R,Mid+1,R,K-x->L->sum);
	}
}

int main(){
	null=Nd;
	*null=(node){null,null,0};
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		las[i]=n+1;
	}
	rt[n+1]=null;
	for (int i=n;i;i--){
		rt[i]=rt[i+1];
		rt[i]=Modify(rt[i],1,n+1,i,1);
		rt[i]=Modify(rt[i],1,n+1,las[A[i]],-1);
		las[A[i]]=i;
	}
	for (int k=1;k<=n;k++){
		int num=0;
		for (int x=1,y;x<=n;x=y+1){
			y=Query(rt[x],1,n+1,k)-1;
			num++;
		}
		printf("%d ",num);
	}
	puts("");
}