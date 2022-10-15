#include<bits/stdc++.h>
#define MAXN 200005
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n1,n2,n3;
int a[MAXN],b[MAXN],c[MAXN];
ll ans;
void solve(int a[],int b[],int c[],int n1,int n2,int n3)
{
    for(int i=1;i<=n2;i++)
    {
        int x=b[i];
        //printf("x=%d %d %d\n",x,a[1],c[n3]);
        if(a[1]>x||c[n3]<x) continue;
        int id=upper_bound(a+1,a+n1+1,x)-a; id--;
        int id2=lower_bound(c+1,c+n3+1,x)-c;
        ans=min(ans,1LL*(x-a[id])*(x-a[id])+1LL*(x-c[id2])*(x-c[id2])+1LL*(c[id2]-a[id])*(c[id2]-a[id]));
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n1,&n2,&n3);
        for(int i=1;i<=n1;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n2;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n3;i++) scanf("%d",&c[i]);
        sort(a+1,a+n1+1); sort(b+1,b+n2+1); sort(c+1,c+n3+1);
        ans=INF;
        solve(a,b,c,n1,n2,n3);
        solve(a,c,b,n1,n3,n2);
        solve(b,a,c,n2,n1,n3);
        solve(b,c,a,n2,n3,n1);
        solve(c,a,b,n3,n1,n2);
        solve(c,b,a,n3,n2,n1);
        printf("%lld\n",ans);
    }
    return 0;
}