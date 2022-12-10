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

const int N=5e5+19;
const int Top=10000000;
const int top=1e9+7;
const int p=1e9+7;

struct node *null;
struct node{
	node *L,*R;
	int mx;
} Nd[Top],*cur=Nd+1,*rt[N];

map<pii,int> M;
map<int,int> l,r,s;
int h,w,n,x,c,tot,res;

struct QType{
	int x,h,f;
	bool operator < (const QType &B) const {return x<B.x;}
} Q[N];

int Qx,Qv,Ql,Qr,Qf;
node *Modify(node *x,int L,int R){
	node *y=cur++;
	if (L==R){
		y->mx=(Qf==1?Qv:0);
		return y;
	}
	if (Qx<=Mid){
		y->L=Modify(x->L,L,Mid);
		y->R=x->R;
	} else{
		y->L=x->L;
		y->R=Modify(x->R,Mid+1,R);
	}
	y->mx=max(y->L->mx,y->R->mx);
	return y;
}
int Query(node *x,int L,int R){
	if (L==R) return L;
	if (x->R->mx>=Qv) return Query(x->R,Mid+1,R);
	return Query(x->L,L,Mid);
}
int Query2(node *x,int L,int R){
	if (Ql<=L&&R<=Qr){
		if (x->mx<Qv) return -1;
		return Query(x,L,R);
	}
	int tmp;
	if (Qr>Mid&&~(tmp=Query2(x->R,Mid+1,R))) return tmp;
	if (Ql<=Mid&&~(tmp=Query2(x->L,L,Mid))) return tmp;
	return -1;
}
int calc(int x,int y){
	if (M.count(mp(x,y))) return M[mp(x,y)];
	int &res=M[mp(x,y)];
	int z;
	Ql=1,Qr=x;Qv=x;
	z=(Ql<=Qr?Query2(rt[y],1,top):-1);
	if (z==-1) return res=1;
	if (x>z+s[z]){
		return res=calc(z-1,y);
	} else{
		if (l[z]==1){
			return res=2*calc(z,r[z]+1)%p;
		} else
		if (r[z]==w){
			return res=2*calc(z,l[z]-1)%p;
		} else{
			return res=(calc(z,r[z]+1)+calc(z,l[z]-1))%p;
		}
	}
}

int main(){
	null=Nd;
	*null=(node){null,null,0};
	h=IN(),w=IN(),n=IN();
	For(i,1,n+1){
		x=IN();
		l[x]=IN(),r[x]=IN(),s[x]=IN();
		Q[++tot]=(QType){l[x],x,1};
		Q[++tot]=(QType){r[x]+1,x,-1};
	}
	sort(Q+1,Q+tot+1);
	rt[0]=null;
	c=1;
	For(i,1,w+1){
		rt[i]=rt[i-1];
		for (;c<=tot&&Q[c].x==i;c++){
			Qx=Q[c].h;
			Qf=Q[c].f;
			Qv=Qx+s[Qx];
			rt[i]=Modify(rt[i],1,top);
		}
	}
	For(i,1,w+1){
//		printf("%d ",calc(h+1,i));
		res=(res+calc(h+1,i))%p;
	}
	puts("");
	printf("%d\n",res);
}