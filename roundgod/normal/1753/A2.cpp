#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]) v.push_back(P(a[i],i));
        }
        if(v.size()&1)
        {
            puts("-1");
            continue;
        }
        if(!v.size())
        {
            puts("1");
            printf("%d %d\n",1,n);
            continue;
        }
        vector<P> ans;
        for(int i=0;i<(int)v.size();i+=2)
        {
            int last=(i==0?1:v[i-1].S+1);
            if(v[i].S>last) ans.push_back(P(last,v[i].S-1));
            if(v[i].F==v[i+1].F)
            {
                if((v[i+1].S-v[i].S)&1) ans.push_back(P(v[i].S,v[i+1].S));
                else 
                {
                    ans.push_back(P(v[i].S,v[i].S));
                    ans.push_back(P(v[i].S+1,v[i+1].S));
                }
            }
            else
            {
                ans.push_back(P(v[i].S,v[i].S));
                if((v[i+1].S-v[i].S)>1) ans.push_back(P(v[i].S+1,v[i+1].S-1));
                ans.push_back(P(v[i+1].S,v[i+1].S));
            }
        }
        if(v.back().S<n) ans.push_back(P(v.back().S+1,n));
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}