#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S secondN
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,x[MAXN],y[MAXN];
map<P,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    bool f=true;
    if(n&1) f=false;
    for(int i=0;i<n/2;i++) if(x[i]+x[i+n/2]!=x[0]+x[n/2]) f=false;
    for(int i=0;i<n/2;i++) if(y[i]+y[i+n/2]!=y[0]+y[n/2]) f=false;
    if(!f) puts("NO"); else puts("YES");
    return 0;
}