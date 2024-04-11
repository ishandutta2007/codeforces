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

const int N=1e6+19;
const int p=1e9+7;

vector<pii> V[N];
int vis[N],cnt[N],A[N],fac[N],id[N];
int n,m,x,tmp,res;

bool cmp(int x,int y){
	return V[x]<V[y];
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	n=IN(),m=IN();
	For(t,1,n+1){
		*A=0;
		for (int k=IN();k--;){
			x=IN();
			if (vis[x]!=t) vis[x]=t,cnt[x]=0,A[++*A]=x;
			cnt[x]++;
		}
		For(i,1,*A+1){
			V[A[i]].pb(mp(t,cnt[A[i]]));
		}
	}
	For(i,1,m+1) id[i]=i;
	sort(id+1,id+m+1,cmp);
	res=1;
	For(i,1,m+1)
		if (!i||V[id[i]]!=V[id[i-1]]){
			res=1ll*res*fac[tmp]%p;
			tmp=1;
		} else{
			tmp++;
		}
	res=1ll*res*fac[tmp]%p;
	printf("%d\n",res);
}