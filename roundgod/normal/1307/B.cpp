#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int need=(x+a[n]-1)/a[n];
        if(need==1)
        {
            bool f=false;
            for(int i=1;i<=n;i++) if(a[i]==x) f=true;
            if(!f) need++;
        }
        printf("%d\n",need);
    }
    return 0;
}