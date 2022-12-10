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

const int N=100000+19;

int n,f[N],g[N],h[N],cnt[N];
int m;

int main(){
	n=IN();
	For(i,1,n+1){
		cnt[f[i]=IN()]++;
	}
	For(i,1,n+1)
		if (cnt[i]&&f[i]!=i){
			puts("-1");
			return 0;
		}
	For(i,1,n+1)
		if (cnt[i]){
			h[++m]=i;
			g[i]=m;
		}
	For(i,1,n+1)
		if (f[i]!=i){
			g[i]=g[f[i]];
		}
	printf("%d\n",m);
	For(i,1,n+1) printf("%d ",g[i]);puts("");
	For(i,1,m+1) printf("%d ",h[i]);puts("");
}