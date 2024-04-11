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
int q,x;
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        int cnt=0,dummy=x;
        while(x)
        {
            cnt++;
            x/=2;
        }
        if(dummy!=(1<<cnt)-1) printf("%d\n",(1<<cnt)-1);
        else
        {
            int curans=1;
            for(int j=2;j*j<=dummy;j++)
            {
                if(dummy%j) continue;
                curans=max(curans,j);
                curans=max(curans,dummy/j);
            }
            printf("%d\n",curans);
        }
    }
    return 0;
}