#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=300005;
typedef long long LL;
int n,val[N],bin[N];
LL s[N],sum,ans;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%lld",&val[i],&s[i]),sum+=val[i];
	if(sum<0) rep(i,1,n) val[i]=-val[i];
	rep(i,1,n) rep(j,0,61) if(s[i]&(1ll<<j)) bin[i]=j;
	rep(j,0,61)
	{
		sum=0;
		rep(i,1,n) if(bin[i]==j) sum+=val[i];
		if(sum>0)
		{
			ans|=(1ll<<j);
			rep(i,1,n) if(s[i]&(1ll<<j)) val[i]=-val[i];	
		}
	}
	printf("%lld\n",ans);
	return 0;
}