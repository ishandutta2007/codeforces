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
        if((a+b+c)%9)
        {
            puts("NO");
            continue;
        }
        int x=(a+b+c)/9;
        if(a<x||b<x||c<x) puts("NO"); else puts("YES");
    }
    return 0;
}