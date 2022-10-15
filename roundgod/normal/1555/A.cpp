#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n&1) n++;
        if(n<=6) puts("15");
        else printf("%lld\n",n*5/2);
    }
    return 0;
}