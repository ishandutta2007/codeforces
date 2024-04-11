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
ll n,k,a[MAXN];
int main()
{
    scanf("%lld",&n);
    if((n*(n+1)/2)&1) puts("1"); else puts("0");
    return 0;
}