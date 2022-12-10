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

const db eps=1e-9;

db f[1<<20],A[20],res[20];
int n,k,c;

int main(){
	n=IN(),k=IN();
	For(i,0,n){
		scanf("%lf",&A[i]);
		if (A[i]>eps) c++;
	}
	if (c<=k){
		For(i,0,n) printf("%d ",A[i]>eps);
		puts("");
		return 0;
	}
	f[0]=1;
	For(t,0,1<<n)
		if (f[t]){
			db tmp=1;
			For(i,0,n) if (t>>i&1) tmp-=A[i];
			if (tmp>eps){
				For(i,0,n) if (!(t>>i&1)) f[t|1<<i]+=f[t]*A[i]/tmp;
			}
			if (__builtin_popcount(t)==k){
				For(i,0,n) if (t>>i&1) res[i]+=f[t];
			}
		}
	For(i,0,n) printf("%.10lf ",res[i]);
	puts("");
}