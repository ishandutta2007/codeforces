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
int n,x;
ll k;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%d",&k,&x);
        printf("%lld\n",(k-1)*9+x);
    }
    return 0;
}