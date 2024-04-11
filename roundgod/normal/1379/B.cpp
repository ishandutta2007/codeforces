#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,l,r;
ll m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%lld",&l,&r,&m);
        int x=r-l;
        for(int i=l;i<=r;i++)
        {
            if(m%i<=x&&m-m%i>0)
            {
                printf("%d %lld %d\n",i,l+m%i,l);
                break;
            }
            if(i-m%i<=x)
            {
                printf("%d %d %lld\n",i,l,l+(i-m%i));
                break;
            }
        }
    }
}