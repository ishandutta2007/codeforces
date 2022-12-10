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

const int N=2000+19;

vector<pii> V;
int A[N],B[N],pos[N];
int n;
ll res;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[IN()]=i;
	For(i,1,n+1) A[i]=B[A[i]],pos[A[i]]=i;
	for (int i=n;i;i--){
		while (pos[i]!=i){
			for (int j=pos[i]+1;j<=i;j++)
				if (A[j]<=pos[i]){
					int x=pos[i],y=j;
					res+=abs(x-y);
					V.pb(mp(x,y));
					pos[A[x]]=y;
					pos[A[y]]=x;
					swap(A[x],A[y]);
					break;
				}
		}
	}
	printf("%I64d\n",res);
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d %d\n",V[i].fi,V[i].se);
}