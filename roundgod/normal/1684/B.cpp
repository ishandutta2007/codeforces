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
int t,a,b,c;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int x=c+1;
        int need=(a-x%b);
        if(need<0) need+=b;
        x+=need;
        printf("%d %d %d\n",x,b,c);
    }
    return 0;
}