#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int main()
{
    scanf("%lld",&n);
    for(int i=2;1LL*i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll tmp=n;
            while(tmp%i==0) tmp/=i;
            if(tmp!=1) {puts("1"); return 0;}
            else {printf("%d\n",i); return 0;}
        }
    }
    printf("%lld\n",n);
    return 0;
}