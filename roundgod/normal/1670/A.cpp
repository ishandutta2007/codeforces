#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0) cnt++;
        }
        for(int i=1;i<=n;i++) a[i]=max(a[i],-a[i]);
        bool f=true;
        for(int i=2;i<=cnt;i++) if(a[i]>a[i-1]) f=false;
        for(int i=cnt+1;i<=n-1;i++) if(a[i]>a[i+1]) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}