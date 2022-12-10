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

const int N=100000+19;

ll S[N],C[N];
int A[N],n;
db res;

void Add(ll *A,int x,ll v){
	for (;x<=n;x+=x&-x) A[x]+=v;
}
ll Qry(ll *A,int x){
	ll res=0;
	for (;x;x-=x&-x) res+=A[x];
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1){
		ll s,c;
		s=Qry(S,A[i]);
		c=Qry(C,A[i]);
		res+=1.0*s*(n-i+1)/n/(n+1);
		res+=(i-1-c)-1.0*(1.0*(i-1)*i/2-s)*(n-i+1)/n/(n+1);
		Add(S,A[i],i);
		Add(C,A[i],1);
	}
	printf("%.20lf\n",res);
}