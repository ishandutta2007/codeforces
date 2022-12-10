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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=1000+19;
const int p=1e9+7;
const db eps=1e-9;
const db pi=acos(-1.0);

bool equ(db a,db b){
	return fabs(a-b)<eps;
}
struct Point{
	db x,y,k;
	bool operator < (const Point &B) const{
		if (!equ(x,B.x)) return x<B.x;
		if (!equ(y,B.y)) return y<B.y;
		if (!equ(k,B.k)) return k<B.k;
		return 0;
	}
} P[N*N];
db x[N],y[N],a,b,c,d,k;
int n,num,tmp,res,tot;

int main(){
	n=IN();
	For(i,1,n+1){
		a=IN(),b=IN(),c=IN(),d=IN();
		a/=b,c/=d;
		x[i]=a/(a*a+c*c);
		y[i]=c/(a*a+c*c);
	}
	For(i,1,n+1)
		For(j,i+1,n+1){
			tot++;
			P[tot].x=x[i]+x[j];
			P[tot].y=y[i]+y[j];
			k=equ(x[i],x[j])?1e50:(y[i]-y[j])/(x[i]-x[j]);
			P[tot].k=k;
		}
	sort(P+1,P+tot+1);
	for (int l=1,r;l<=tot;l=r+1){
		for (r=l;r+1<=tot&&equ(P[l].x,P[r+1].x)&&equ(P[l].y,P[r+1].y);r++);
		num=1;tmp=1;
		For(i,l,r+1)
			if (i==l||!equ(P[i].k,P[i-1].k)){
				num=1ll*num*tmp%p;
				tmp=2;
			} else{
				tmp++;
			}
		num=1ll*num*tmp%p;
		num=(num+p-(r-l+2))%p;
		res=(res+num)%p;
	}
	printf("%d\n",res);
}