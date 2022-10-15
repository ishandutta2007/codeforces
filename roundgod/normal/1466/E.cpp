#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll x[MAXN];
int val[62];
int cnt[62];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    val[0]=1;
    for(int i=1;i<60;i++) val[i]=2LL*val[i-1]%MOD;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&x[i]);
            for(int j=0;j<60;j++)
            {
                if(x[i]&(1LL<<j)) cnt[j]++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int lhs=0,rhs=0;
            for(int j=0;j<60;j++)
            {
                add(rhs,1LL*val[j]*n%MOD);
                if(x[i]&(1LL<<j)) 
                {
                    add(lhs,1LL*val[j]*cnt[j]%MOD);
                }
                else
                {
                    dec(rhs,1LL*val[j]*(n-cnt[j])%MOD);
                }
            }
            add(ans,1LL*lhs*rhs%MOD);
        }
        printf("%d\n",ans);
    }
    return 0;
}