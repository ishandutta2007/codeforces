#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n;
ll h[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
    ll s=0;
    for(int i=1;i<=n;i++) s+=h[i];
    ll sum=1LL*(0+n-1)*n/2;
    assert(s>=sum);
    ll d=(s-sum)/n;
    int r=(s-sum)%n;
    for(int i=1;i<=n;i++) printf("%lld ",i-1+d+(i<=r));
    puts("");
    return 0;
}