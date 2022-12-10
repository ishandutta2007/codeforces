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
const int oo=(1<<30)-1;

struct node{
	int w,v;
	bool operator < (const node &B) const{
		return w<B.w;
	}
} C[N],D[N];
int mxC[N],mxD[N];
int c,d,n,cw,dw,v,w,x,y,res;
char typ[5];

int main(){
	n=IN(),cw=IN(),dw=IN();
	For(i,1,n+1){
		v=IN(),w=IN(),scanf("%s",typ);
		if (typ[0]=='C'){
			if (w<=cw) C[++c]=(node){w,v};
		} else{
			if (w<=dw) D[++d]=(node){w,v};
		}
	}
	sort(C+1,C+c+1);
	sort(D+1,D+d+1);
	For(i,1,c+1) mxC[i]=max(C[i].v,mxC[i-1]);
	For(i,1,d+1) mxD[i]=max(D[i].v,mxD[i-1]);
	For(i,1,c+1) x=max(x,C[i].v);
	For(i,1,d+1) y=max(y,D[i].v);
	if (x&&y) res=x+y;
	for (int i=0,j=c;j;j--){
		i=min(i,j-1);
		while (i+1<j&&C[i+1].w+C[j].w<=cw) i++;
		if (i) res=max(res,mxC[i]+C[j].v);
	}
	for (int i=0,j=d;j;j--){
		i=min(i,j-1);
		while (i+1<j&&D[i+1].w+D[j].w<=dw) i++;
		if (i) res=max(res,mxD[i]+D[j].v);
	}
	printf("%d\n",res);
}