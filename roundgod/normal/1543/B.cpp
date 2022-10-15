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
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll s=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        int x=s%n;
        printf("%lld\n",1LL*x*(n-x));
    }
    return 0;
}