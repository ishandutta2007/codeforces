#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll x,y;
        x=0; y=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(i&1) x+=a[i]; else y+=a[i];
        }
        if(x>=y)
        {
            for(int i=1;i<=n;i++) printf("%d ",i&1?a[i]:1);
        }
        else for(int i=1;i<=n;i++) printf("%d ",i&1?1:a[i]);
        puts("");
    }
    return 0;
}