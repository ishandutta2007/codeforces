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

const int N=1e6+19;

int fa[N],d[N],vis[N];
int n,m,c,x,y,r;
ll res;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1) fa[i]=i;
	For(i,0,m){
		x=IN(),y=IN();
		vis[x]=1;
		vis[y]=1;
		if (x==y){
			c++;
		} else{
			d[x]++;
			d[y]++;
			Union(x,y);		
		}
	}
	For(i,1,n+1) if (vis[i]) r=i;
	For(i,1,n+1){
		if (vis[i]&&getf(i)!=getf(r)) return puts("0"),0;
	}
	res=1ll*c*(c-1)/2+1ll*c*(m-c);
	For(i,1,n+1) res=(res+1ll*d[i]*(d[i]-1)/2);
	cout<<res<<endl;
}