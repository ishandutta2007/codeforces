#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,d;
int a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
        {
            int x=min(a[i],d/(i-1));
            a[i]-=x; a[1]+=x; d-=(i-1)*x;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}