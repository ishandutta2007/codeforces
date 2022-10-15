#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        bool f=true;
        for(int i=1;i<=n-1;i++)
        {
            if(a[i]<0)
            {
                f=false;
                break;
            }
            else if(!a[i]) break;
            a[i+1]+=a[i];
            a[i]=0;
        }
        for(int i=1;i<=n;i++) if(a[i]!=0) f=false;
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}