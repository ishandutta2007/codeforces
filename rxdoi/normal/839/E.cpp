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
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=40+3;

ll A[N];
int adj[N][N],id[N],deg[N];
int n,k,mx;
db res;

bool cmp(int x,int y){
	return deg[x]<deg[y];
}
void dfs(ll B,int c){
	if (c+__builtin_popcountll(B)<=mx) return;
	if (B==0){
		mx=c;
		return;
	}
	int x=__builtin_ctzll(B);
	dfs(B&A[x],c+1);
	dfs(B^(1ll<<x),c);
}

int main(){
	n=IN(),k=IN();
	For(i,0,n) For(j,0,n){
		adj[i][j]=IN();
		if (adj[i][j]) deg[i]++,deg[j]++;
	}
	For(i,0,n) id[i]=i;
	sort(id,id+n,cmp);
	For(i,0,n) For(j,0,n){
		if (adj[id[i]][id[j]]==1) A[i]|=1ll<<j;
	}
	dfs((1ll<<n)-1,0);
	res=1.0*k*k/mx*(mx-1)/2;
	printf("%.10lf\n",res);
}