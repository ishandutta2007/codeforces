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

const int N=200000+19;

int A[N],n;
db B[N],l,r,res,tmp;

db calc(db x){
	res=0;
	For(i,1,n+1) B[i]=A[i]-x;
	tmp=0;
	For(i,1,n+1){
		tmp=max(tmp,0.0)+B[i];
		res=max(res,abs(tmp));
	}
	tmp=0;
	For(i,1,n+1){
		tmp=min(tmp,0.0)+B[i];
		res=max(res,abs(tmp));
	}
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	l=-10000,r=10000;
	For(i,0,100){
		db t=(r-l)/3.0;
		db t1=l+t,t2=r-t;
		if (calc(t1)>calc(t2)) l=t1;else r=t2;
	}
	printf("%.10lf\n",calc(l));
}