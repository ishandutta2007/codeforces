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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=30;
const int oo=(1<<30)-1;

map<pii,pii> M;
int A[N],B[N],C[N],v[N];
int n,top,mx=-oo;
pii res;

void dfs_1(int x,int a,int b,int c,int s){
	if (x>top){
		pii tmp=mp(b-a,c-a);
		if (!M.count(tmp)||M[tmp]<mp(a,s)) M[tmp]=mp(a,s);
		return;
	}
	dfs_1(x+1,a+A[x],b+B[x],c,s*3+0);
	dfs_1(x+1,a+A[x],b,c+C[x],s*3+1);
	dfs_1(x+1,a,b+B[x],c+C[x],s*3+2);
}
void dfs_2(int x,int a,int b,int c,int s){
	if (x>n){
		pii tmp=mp(a-b,a-c);
		if (M.count(tmp)){
			int v=M[tmp].fi;
			if (v+a>mx){
				mx=v+a;
				res=mp(M[tmp].se,s);
			}
		}
		return;
	}
	dfs_2(x+1,a+A[x],b+B[x],c,s*3+0);
	dfs_2(x+1,a+A[x],b,c+C[x],s*3+1);
	dfs_2(x+1,a,b+B[x],c+C[x],s*3+2);
}

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		B[i]=IN();
		C[i]=IN();
	}
	top=n/2;
	dfs_1(1,0,0,0,0);
	dfs_2(top+1,0,0,0,0);
	if (mx==-oo){
		puts("Impossible");
	} else{
		for (int i=top;i;i--) v[i]=res.fi%3,res.fi/=3;
		for (int i=n;i>top;i--) v[i]=res.se%3,res.se/=3;
		For(i,1,n+1){
			if (v[i]==0) puts("LM");
			if (v[i]==1) puts("LW");
			if (v[i]==2) puts("MW");
		}
	}
}