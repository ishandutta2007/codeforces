#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll k,d;
int maxi,mini;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k>4) k=4+(k&1);
        for(int i=0;i<k;i++)
        {
            mini=INF,maxi=-INF;
            for(int i=1;i<=n;i++) 
            {
                mini=min(mini,a[i]);
                maxi=max(maxi,a[i]);
            }
            for(int i=1;i<=n;i++) a[i]=maxi-a[i];
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}