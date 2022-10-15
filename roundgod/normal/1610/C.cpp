#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
bool check(int x)
{
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(now-1<=b[i]&&x-now<=a[i]) now++;
        if(now==x+1) return true; 
    }
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        int l=0,r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}