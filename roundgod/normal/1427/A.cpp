#include<bits/stdc++.h>
#define MAXN 1000005
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
        int s=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if(s==0)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        if(s>0) sort(a+1,a+n+1,greater<int>()); else sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}