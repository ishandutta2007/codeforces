#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        ll x=1;
        bool f=false;
        while(x<=n)
        {
            if((n-x)%b==0) {f=true; break;}
            if(a==1) break;
            x=x*a;
        }
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}