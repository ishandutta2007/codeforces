/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n,m;
char s[55][25];
ll hv[1<<21];
lf dp[1<<21];

int main(){
	scanf("%d",&n);
	loop(i,n)scanf("%s",s[i]);
	m=strlen(s[0]);
	loop(j,n)loop(i,j){
		int ms=0;
		loop(k,m)if(s[i][k]==s[j][k])ms|=1<<k;
		hv[ms]|=(1ll<<i)|(1ll<<j);
	}
	range(i,(1<<m)-1,0,-1)for(int j=i;j;j-=j&-j)hv[i^(j&-j)]|=hv[i];
	dp[0]=1;
	lf ans=0;
	loop(i,1<<m){
		lf gl=dp[i]/(m-__builtin_popcount(i));
		for(int j=((1<<m)-1)^i;j;j-=j&-j)dp[i|(j&-j)]+=gl;
		ans+=dp[i]*__builtin_popcountll(hv[i]);
	}
	printf("%.15Lf\n",ans/n);
	return 0;
}