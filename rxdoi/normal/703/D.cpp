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

const int N=1000000+19;

map<int,int> M;
vector<pii> V[N];
int pre[N],A[N],Ans[N],S[N];
int n,m,l,r;

int C[N];
void Add(int x,int v){
	for (;x<=n;x+=x&-x) C[x]^=v;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res^=C[x];
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		if (M.count(A[i])) pre[i]=M[A[i]];
		M[A[i]]=i;
		S[i]=S[i-1]^A[i];
	}
	m=IN();
	For(i,1,m+1){
		l=IN(),r=IN();
		V[r].pb(mp(l,i));
		Ans[i]=S[r]^S[l-1];
	}
	For(i,1,n+1){
		//pre[i]+1..i
		Add(pre[i]+1,A[i]);
		Add(i+1,A[i]);
		For(j,0,V[i].size()){
			Ans[V[i][j].se]^=Qry(V[i][j].fi);
		}
	}
	For(i,1,m+1) printf("%d\n",Ans[i]);
}