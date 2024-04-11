#include<bits/stdc++.h>
#define MAXN 250005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c,d,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        bool f=false;
        for(int i=0;i<=k;i++)
        {
            if(c*i>=a&&d*(k-i)>=b)
            {
                printf("%d %d\n",i,k-i);
                f=true;
                break;
            }
        }
        if(!f) puts("-1");
    }
    return 0;
}