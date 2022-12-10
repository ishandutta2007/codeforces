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
int A[N],mx[N],suf[N],sum[N];
int n,len;
ll res;

void Work(int d){
	if (d==n) return;
	memset(mx,0,sizeof(mx));
	For(i,1,n+1) mx[i%d]=max(mx[i%d],A[i]);
	for (int i=n;i;i--){
		if (mx[i%d]==A[i]) suf[i]=suf[i+1]+1;else suf[i]=0;
	}
	memset(sum,0,sizeof(sum));
	For(i,0,V[d].size()) sum[V[d][i]]++;
	For(i,1,n+1) sum[i]+=sum[i-1];
	For(i,1,n+1){
		len=suf[i];
		if (len==n-i+1) len+=suf[1];
		len=min(len,n);
		res+=sum[len];
	}
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) V[__gcd(i,n)].pb(i);
	for (int d=1;d*d<=n;d++)
		if (n%d==0){
			Work(d);
			if (d*d!=n) Work(n/d);
		}
	printf("%I64d\n",res);
}