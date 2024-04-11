#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        vector<P> v1,v2;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            int cnt=1;
            while(x%m==0) x/=m,cnt*=m;
            if(v1.size()&&v1.back().F==x) {v1[v1.size()-1].S+=cnt;} else v1.push_back(P(x,cnt));
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            int x;
            scanf("%d",&x);
            int cnt=1;
            while(x%m==0) x/=m,cnt*=m;
            if(v2.size()&&v2.back().F==x) {v2[v2.size()-1].S+=cnt;} else v2.push_back(P(x,cnt));
        }
        if(v1==v2) puts("Yes"); else puts("No");
    }
    return 0;
}