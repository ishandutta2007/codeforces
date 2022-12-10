#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__V_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;

Vi V[N],pri;
set<int> S[N];
int mx[N],nxt[N],phi[N];
int n,p,x,st,pre;

int Pow(int a,int b,int p){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
int inv(int x,int p){
	return Pow(x,phi[p]-1,p);
}

void dfs(int p,int x){
	if (x) V[x].pb(p);
	phi[p]=p;
	for (int i:pri)
		if (p%i==0){
			dfs(p/i,p);
			phi[p]=phi[p]/i*(i-1);
		}
}
void calc(int p){
	for (int d=2;d*d<=p;d++)
		if (p%d==0){
			pri.pb(d);
			while (p%d==0) p/=d;
		}
	if (p>1) pri.pb(p);
}
void dfs(int d){
	if (!mx[d]) return;
	for (int i:S[d]){
		int x=__gcd(pre,p),y=pre/x,z=i/d;
		printf("%d ",1ll*d/x*inv(y,p/d)%p*z%p);
		pre=i;
	}
	dfs(nxt[d]);
}

int main(){
	n=IN(),p=IN();
	For(i,0,p){
		S[__gcd(i,p)].insert(i);
	}
	For(i,0,n){
		x=IN();
		S[__gcd(x,p)].erase(x);
	}
	calc(p);
	dfs(p,0);
	for (int i=p;i;i--){
		mx[i]+=S[i].size();
		for (int j:V[i]){
			if (mx[i]>mx[j]) mx[j]=mx[i],nxt[j]=i;
		}
	}
	For(i,1,p+1) if (!st||mx[i]>mx[st]) st=i;
	if (!st){
		puts("0");
		return 0;
	}
	pre=1;
	printf("%d\n",mx[st]);
	dfs(st);
	puts("");
}