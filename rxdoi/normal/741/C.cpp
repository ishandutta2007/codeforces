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

const int N=2e5+19;

Vi V[N];
int vis[N],A[N],B[N],res[N];
int n;

void dfs(int x,int val){
	if (vis[x]) return;
	vis[x]=1,res[x]=val;
	For(i,0,V[x].size()) dfs(V[x][i],val^1);
}

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN(),B[i]=IN();
		V[A[i]].pb(B[i]);
		V[B[i]].pb(A[i]);
	}
	For(i,1,n+1){
		V[2*i].pb(2*i+1);
		V[2*i+1].pb(2*i);
	}
	For(i,1,2*n+1) dfs(i,0);
	For(i,1,n+1){
		printf("%d %d\n",res[A[i]]+1,res[B[i]]+1);
	}
}