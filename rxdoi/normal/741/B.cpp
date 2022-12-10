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

Vi A[N];
int f[2][N],fa[N],w[N],v[N],W[N],V[N];
int n,m,maxW,c;

void Upd(int &x,int y){
	x=max(x,y);
}
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y){
		fa[x]=y;
		W[y]+=W[x];
		V[y]+=V[x];
		For(i,0,A[x].size()) A[y].pb(A[x][i]);
	}
}

int main(){
	n=IN(),m=IN(),maxW=IN();
	For(i,1,n+1) w[i]=IN();
	For(i,1,n+1) v[i]=IN();
	For(i,1,n+1){
		fa[i]=i;
		W[i]=w[i];
		V[i]=v[i];
		A[i].pb(i);
	}
	For(i,1,m+1) Union(IN(),IN());
	For(i,1,n+1)
		if (fa[i]==i){
			c^=1;
			For(j,0,maxW+1) f[c][j]=f[c^1][j];
			For(j,W[i],maxW+1) Upd(f[c][j],f[c^1][j-W[i]]+V[i]);
			for (int x:A[i]){
				For(j,w[x],maxW+1) Upd(f[c][j],f[c^1][j-w[x]]+v[x]);
			}
		}
	printf("%d\n",f[c][maxW]);
}