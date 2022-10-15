#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,h[MAXN],tmp[MAXN];
bool check(int x)
{
    for(int i=1;i<=n;i++) tmp[i]=h[i];
    for(int i=n;i>=1;i--)
    {
        if(tmp[i]<x) return false;
        if(i>=3)
        {
            int val=min(h[i]/3,max(0,(tmp[i]-x)/3));
            tmp[i]-=3*val; tmp[i-1]+=val; tmp[i-2]+=2*val;
        }
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        int l=0,r=INF;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}