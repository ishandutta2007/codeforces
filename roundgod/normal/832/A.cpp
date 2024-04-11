#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    scanf("%I64d %I64d",&n,&k);
    ll x=n/k;
    if(x%2==1) printf("YES\n"); else printf("NO\n");
    return 0;
}