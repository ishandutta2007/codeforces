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

const int N=1000+19;

struct node{
	int val;
	node *R,*D;
} Nd[N][N],*rt,*x,*y,*A,*B,*C,*D,*E,*F,*G,*H;
int n,m,Qc,a,b,c,d,h,w;

node *go(int x,int y){
	node *a=rt;
	For(i,0,x) a=a->D;
	For(i,0,y) a=a->R;
	return a;
}

int main(){
	n=IN(),m=IN(),Qc=IN();
	For(i,1,n+1){
		For(j,1,m+1) Nd[i][j].val=IN();
	}
	For(i,0,n) For(j,0,m+1) Nd[i][j].D=&Nd[i+1][j];
	For(i,0,n+1) For(j,0,m) Nd[i][j].R=&Nd[i][j+1];
	rt=&Nd[0][0];
	while (Qc--){
		a=IN(),b=IN(),c=IN(),d=IN(),h=IN(),w=IN();
		
		A=go(a,b+w-1);	B=go(c,d+w-1);
		C=go(a+h-1,b);	D=go(c+h-1,d);
		E=go(a,b-1);	F=go(c,d-1);
		G=go(a-1,b);	H=go(c-1,d);
		
		x=A;y=B;
		For(i,0,h){
			swap(x->R,y->R);x=x->D,y=y->D;
		}
		x=C;y=D;
		For(i,0,w){
			swap(x->D,y->D);x=x->R,y=y->R;
		}
		
		x=E;y=F;
		For(i,0,h){
			swap(x->R,y->R);x=x->D,y=y->D;
		}
		x=G;y=H;
		For(i,0,w){
			swap(x->D,y->D);x=x->R,y=y->R;
		}
	}
	x=rt;
	For(i,1,n+1){
		x=x->D,y=x;
		For(j,1,m+1) y=y->R,printf("%d ",y->val);
		puts("");
	}
}