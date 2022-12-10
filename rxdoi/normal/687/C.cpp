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
#define fir first
#define sec second

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

const int N=500+19;

Vi V;
bool f[N],g[N][N];
int A[N];
int n,K;

int main(){
	n=IN(),K=IN();
	For(i,1,n+1) A[i]=IN();
	f[0]=1;
	g[0][0]=1;
	For(i,1,n+1){
		for (int j=K;j>=A[i];j--)
			if (f[j-A[i]]){
				f[j]=1;
				For(k,0,j+1) g[j][k]|=g[j-A[i]][k];
				for (int k=j;k>=A[i];k--) g[j][k]|=g[j-A[i]][k-A[i]];
			}
	}
	For(i,0,K+1){
		if (g[K][i]) V.pb(i);
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);
	puts("");
}