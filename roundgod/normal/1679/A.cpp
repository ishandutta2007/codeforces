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
int t;
ll n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n&1||n==2) {puts("-1"); continue;}
        ll a=n/4; ll rem=n-a*4,b=0;
        while(rem%6) a--,rem+=4;
        b=rem/6;
        printf("%lld %lld\n",a+b-a/3,a+b);
    }
    return 0;
}