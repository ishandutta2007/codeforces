#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
int X,d;
int find(int x){int s=1;while((1ll<<(s+1))-1<=x)++s;return s;}
ll s[10005],ans=0;
int main(){
	scanf("%d%d",&X,&d);
	ll cnt=1;
	while(X){
		int p=find(X);X-=(1<<p)-1;
		rep(i,p)s[++ans]=cnt;
		cnt+=P;
	}
	printf("%lld\n",ans);
	rep(i,ans)printf("%lld%c",s[i],i==ans?'\n':' ');
	return 0;
}