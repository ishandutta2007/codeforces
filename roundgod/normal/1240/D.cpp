#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define BASE1 19260817
#define BASE2 19991020
#define MOD1 1000000007
#define MOD2 998244383
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,a[MAXN];
map<P,int> mp;
int t,st[MAXN],hsh1[MAXN],hsh2[MAXN];
void go()
{
    mp[P(hsh1[t-1],hsh2[t-1])]++;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        hsh1[0]=hsh2[0]=0;
        t=1;
        mp.clear();
        mp[P(0,0)]++;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(t>1&&st[t-1]==a[i]) t--;
            else
            {
                hsh1[t]=(1LL*BASE1*hsh1[t-1]+a[i])%MOD1;
                hsh2[t]=(1LL*BASE2*hsh2[t-1]+a[i])%MOD2;
                st[t]=a[i];
                t++;
            }
            go();
        }
        ll ans=0;
        for(auto p:mp) ans+=1LL*(p.S)*(p.S-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}