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
int t,n,m,sx,sy,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&d);
        if(((sx-d>1)&&(sy+d<m))||((sy-d>1)&&(sx+d<n))) printf("%d\n",n+m-2);
        else puts("-1");
    }
    return 0;
}