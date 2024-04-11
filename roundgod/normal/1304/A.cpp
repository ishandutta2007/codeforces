#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x,y,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        if((y-x)%(a+b)) puts("-1"); else printf("%d\n",(y-x)/(a+b));
    }
    return 0;
}