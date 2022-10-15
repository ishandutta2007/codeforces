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
        scanf("%d",&n);
        if(n==4) puts("2 1 3 4");
        else if(n==5) puts("1 2 3 4 5");
        else if(n==6) puts("4 5 1 2 3 6");
        else if(n&1)
        {
            printf("1 ");
            for(int i=n-2;i>=2;i--) printf("%d ",i);
            printf("%d %d",n-1,n);
            puts("");
        }
        else
        {
            for(int i=n-2;i>=1;i--) printf("%d ",i);
            printf("%d %d",n-1,n);
            puts("");
        }
    }
    return 0;
}