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

int n,w,v,u,x,y,b1,b2;
db mx;

int main(){
	n=IN(),w=IN(),v=IN(),u=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		if (1.0*y*v>1.0*u*x) b1=1;
		if (1.0*y*v<1.0*u*x){
			b2=1;
			mx=max(mx,1.0*x/v+1.0*(w-y)/u);
		}
	}
	if (!b1||!b2){
		printf("%.10lf\n",1.0*w/u);
	} else{
		printf("%.10lf\n",mx);
	}
}