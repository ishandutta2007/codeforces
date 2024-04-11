#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,r1,c1,r2,c2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&r1,&c1,&r2,&c2);
        int x=(r1<=r2?r2-r1:n-r1+n-r2);
        int y=(c1<=c2?c2-c1:m-c2+m-c1);
        printf("%d\n",min(x,y));
    }
    return 0;
}