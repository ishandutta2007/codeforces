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
        scanf("%d%d",&n,&k);
        for(int i=n-k+1;i<=n;i++) scanf("%d",&a[i]);
        bool f=true;
        for(int i=n-k+1;i<=n-2;i++) if(a[i+1]-a[i]>a[i+2]-a[i+1]) {f=false; break;}
        if(!f) {puts("NO"); continue;}
        if(k==1)
        {
            puts("YES");
            continue;
        }
        if(k==n)
        {
            if(a[2]-a[1]>=a[1]) puts("YES"); else puts("NO");
            continue;
        }
        int d=a[n-k+2]-a[n-k+1];
        if(a[n-k+1]>1LL*d*(n-k+1)) f=false; 
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}