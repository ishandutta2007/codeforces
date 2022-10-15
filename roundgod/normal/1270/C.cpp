#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
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
        ll x=0,y=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            x+=a[i];
            y^=a[i];
        }
        puts("2");
        printf("%lld ",y);
        x+=y;
        printf("%lld\n",x);
    }
    return 0;
}