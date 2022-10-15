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
        if(n%2==0)
        {
            for(int i=1;i<=n/2;i++) printf("%d %d ",2*i,2*i-1);
            puts("");
        }
        else
        {
            printf("1 ");
            for(int i=1;i<=n/2;i++) printf("%d %d ",2*i+1,2*i);
            puts("");
        }
    }
    return 0;
}