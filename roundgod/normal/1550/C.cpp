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
bool check(int x,int y,int z)
{
    if(a[x]<=a[y]&&a[y]<=a[z]) return false;
    if(a[x]>=a[y]&&a[y]>=a[z]) return false;
    return true;
}
bool check_three(int l)
{
    return check(l,l+1,l+2);
}
bool check_four(int l)
{
    return check(l,l+1,l+2)&&check(l,l+1,l+3)&&check(l,l+2,l+3)&&check(l+1,l+2,l+3);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=2*n-1;
        for(int i=1;i+2<=n;i++) if(check_three(i)) ans++;
        for(int i=1;i+3<=n;i++) if(check_four(i)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}