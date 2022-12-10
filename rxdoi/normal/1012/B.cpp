#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';
	return !f?x:-x;
}

const int N=200000+19;

int fa[2*N],vx[N],vy[N];
int n,m,x,y,q,ans;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}

int main(){
	n=IN(),m=IN(),q=IN();
	For(i,1,n+m+1) fa[i]=i;
	For(i,1,q+1){
		x=IN(),y=IN();
		Union(x,y+n);
	}
	For(i,1,n+m+1) if (fa[i]==i) ans++;
	printf("%d\n",ans-1);
}