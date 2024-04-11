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
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cur=0;
        for(int i=n-1;i>=1;i--)
        {
            int now=a[i]-cur;
            if(now>a[i+1])
            {
                cur+=now-a[i+1];
            }
            a[i]-=cur;
        }
        bool f=true;
        for(int i=1;i<=n;i++) if(a[i]<0) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}