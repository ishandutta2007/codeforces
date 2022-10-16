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
        bool f=true,g=true;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=i) f=false;
            if(a[i]!=n+1-i) g=false;
        }
        if(f) puts("0");
        else if(a[1]==1||a[n]==n) puts("1");
        else if(a[1]==n&&a[n]==1) puts("3");
        else puts("2");
    }
    return 0;
}