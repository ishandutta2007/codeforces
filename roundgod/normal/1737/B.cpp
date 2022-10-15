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
int t,n,k,a[MAXN];
ll solve(ll r)
{
    ll mid=sqrt(r);
    while((mid+1)*(mid+1)<=r) mid++;
    while(mid*mid>r) mid--;
    ll num=3*(mid-1)+1;
    if(mid*(mid+1)<=r) num++;
    if(mid*(mid+2)<=r) num++;
    return num;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}