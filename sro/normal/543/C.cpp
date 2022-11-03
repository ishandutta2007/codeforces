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
char s[25][25];
int a[25][25];
int dp[1<<21];
int val[1<<21];

int main(){
	scanf("%d%d",&n,&m);
	loop(i,n)scanf("%s",s[i]);
	memset(val,0x3f,sizeof(val));
	vector<int> hv;
	loop(i,n)hv.pub(1<<i);
	loop(i,n)loop(j,m)scanf("%d",a[i]+j),val[1<<i]=min(val[1<<i],a[i][j]);
	loop(i,m)loop(j,26){
		int st=0,sm=0,ex=0;
		loop(k,n)if(s[k][i]==j+'a'){
			st|=1<<k;sm+=a[k][i];
			ex=max(ex,a[k][i]);
		}
		if(!st)continue;
		if(val[st]==Inf)hv.pub(st);
		val[st]=min(val[st],sm-ex);
	}
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	loop(i,1<<n)foreach(j,hv)dp[i|*j]=min(dp[i|*j],dp[i]+val[*j]);
	return 0&printf("%d\n",dp[(1<<n)-1]);
}