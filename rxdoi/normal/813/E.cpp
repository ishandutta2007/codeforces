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

struct node *null;
struct node{
	node *L,*R;
	int sum;
} Nd[Top],*cur=Nd+1,*rt[N];
Vi V[N];
int n,k,Ql,Qr,l,r,ans,x;

void copy(node *&x){
	node *y=cur++;*y=*x;x=y;
}
void Modify(node *&x,int L,int R){
	copy(x);
	if (Ql<=L&&R<=Qr){
		x->sum++;
		return;
	}
	if (Ql<=Mid) Modify(x->L,L,Mid);
	if (Qr>Mid) Modify(x->R,Mid+1,R);
}
void Query(node *x,int L,int R,int Qx){
	ans+=x->sum;
	if (L==R) return;
	Qx<=Mid?Query(x->L,L,Mid,Qx):Query(x->R,Mid+1,R,Qx);
}

int main(){
	null=Nd;
	*null=(node){null,null,0};
	n=IN(),k=IN();
	rt[0]=null;
	For(i,1,n+1){
		rt[i]=rt[i-1];
		x=IN();
		V[x].pb(i);
		if (V[x].size()<=k){
			Ql=1;
		} else{
			Ql=V[x][int(V[x].size())-1-k]+1;
		}
		Qr=i;
		Modify(rt[i],1,n);
	}
	for (int q=IN();q--;){
		l=(IN()+ans)%n+1;
		r=(IN()+ans)%n+1;
		if (l>r) swap(l,r);
		ans=0;
		Query(rt[r],1,n,l);
		printf("%d\n",ans);
	}
}