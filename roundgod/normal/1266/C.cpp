#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int r,c;
int main()
{
    scanf("%d%d",&r,&c);
    if(r==1&&c==1) puts("0");
    else if(c==1)
    {
         for(int i=1;i<=r;i++)
        {
            printf("%d\n",i+1);
        }
    }
    else
    {
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                printf("%d ",i*(r+j)/__gcd(i,r+j));
            }
            puts("");
        }
    }
    
    return 0;
}