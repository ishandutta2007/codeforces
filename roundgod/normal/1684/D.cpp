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
int t,n,k,a[MAXN];
ll sum;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        sum=0;
        multiset<int> s;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            s.insert(a[i]-(n-i));
        }
        for(int i=1;i<=k;i++)
        {
            auto it=(--s.end());
            ll delta=((*it)+(i-1));
            if(delta<0) break;
            sum-=delta;
            s.erase(--s.end());
        }
        printf("%lld\n",sum);
    }
    return 0;
}