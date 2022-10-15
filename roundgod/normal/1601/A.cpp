#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int g=0;
        for(int i=0;i<30;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++) if(a[j]&(1<<i)) cnt++;
            g=__gcd(cnt,g);
        }
        if(g==0) for(int i=1;i<=n;i++) printf("%d ",i);
        else for(int i=1;i<=min(g,n);i++) if(g%i==0) printf("%d ",i);
        puts("");
    }
    return 0;
}