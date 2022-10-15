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
        puts("2");
        for(int i=1;i<=n;i++)
        {
            if(i%2==0) continue;
            int j=i;
            while(j<=n) {printf("%d ",j); j=j*2;}
        }
        puts("");
    }
    return 0;
}