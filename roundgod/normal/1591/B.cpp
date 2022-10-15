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
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int now=n,ans=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i]>a[now]) {ans++; now=i;}
        }
        printf("%d\n",ans);
    }
    return 0;
}