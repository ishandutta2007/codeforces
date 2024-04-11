#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a,b,c,d;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(b<a&&d>=c) puts("-1");
        else if(b>=a) printf("%d\n",b);
        else 
        {
            int t=a-b;
            int turns=(t-1)/(c-d)+1;
            printf("%lld\n",b+1LL*turns*c);
        }
    }
    return 0;
}