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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e6+19;
const int p=1e9+7;

int f[2][N],A[N],B[N],s[N],ss[N];
int n,k,c,cnt,res;
ll l;

void U(int &x,ll y) {x=(x+y)%p;}

int main(){
	n=IN(),l=IN(),k=IN();
	cnt=l/n%p;
	For(i,0,n) A[i]=B[i+1]=IN();
	sort(B+1,B+n+1);
	For(i,0,n) A[i]=lower_bound(B+1,B+n+1,A[i])-B;
	For(i,0,n) s[A[i]]++;
	For(i,0,l%n) ss[A[i]]++;
	f[c][0]=1;
	for (int t=0;t<=k&&t<=l/n;t++){
		if (t>0){
			For(i,1,n+1) U(res,1ll*f[c][i]*(cnt-t+1+p));
		}
		For(i,1,n+1) U(f[c][i],f[c][i-1]);
		if (t<k){
			For(i,1,n+1) U(res,1ll*ss[i]*f[c][i]);
		}
		c^=1;
		For(i,0,n+1) f[c][i]=0;
		For(i,1,n+1) U(f[c][i],1ll*s[i]*f[c^1][i]);
	}
	printf("%d\n",res);
}