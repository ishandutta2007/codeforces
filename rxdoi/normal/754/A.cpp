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

const int N=100+19;

vector<pii> V;
int A[N];
int n,b,l,r;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) if (A[i]) b=1;
	if (!b) return puts("NO"),0;
	puts("YES");
	l=1;
	for (r=l;r+1<=n&&A[r]==0;r++);
	for (;r+1<=n&&A[r+1]==0;r++);
	V.pb(mp(l,r));
	l=r+1;
	for (;l<=n;l=r+1){
		for (r=l;r+1<=n&&A[r+1]==0;r++);
		V.pb(mp(l,r));
	}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d %d\n",V[i].fi,V[i].se);
}