#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXN=100;
const int MAXV=200000;
int n,sum,a[MAXN+5];
bool dp[MAXV+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++) for(int j=MAXV;j>=a[i];j--) dp[j]|=dp[j-a[i]];
	if((sum&1)||(!dp[sum>>1])) return puts("0"),0;
	int mn=0x3f3f3f3f;for(int i=1;i<=n;i++) chkmin(mn,a[i]&-a[i]);
	for(int i=1;i<=n;i++) a[i]/=mn;
	for(int i=1;i<=n;i++) if(a[i]&1) return printf("1\n%d\n",i),0;
	return 0;
}