#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
ll w[MAXN],h[MAXN],c[MAXN];
vector<ll> disw,dish;
vector<P> num[MAXN];
int main()
{
	scanf("%d",&n);
	ll g=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&w[i],&h[i],&c[i]);
		g=__gcd(g,c[i]);
	}
	for(int i=0;i<n;i++)
    {
        c[i]/=g;
        disw.push_back(w[i]);
        dish.push_back(h[i]);
    }
    sort(disw.begin(),disw.end()); disw.erase(unique(disw.begin(),disw.end()),disw.end());
    sort(dish.begin(),dish.end()); dish.erase(unique(dish.begin(),dish.end()),dish.end());
    for(int i=0;i<n;i++)
    {
        w[i]=lower_bound(disw.begin(),disw.end(),w[i])-disw.begin();
        h[i]=lower_bound(dish.begin(),dish.end(),h[i])-dish.begin();
        num[w[i]].push_back(P(h[i],c[i]));
    }
    int sz=(int)disw.size();
    for(int i=0;i<sz;i++)
    {
        sort(num[i].begin(),num[i].end());
        ll gg=0;
        for(int j=0;j<(int)num[i].size();j++) gg=__gcd(gg,num[i][j].S);
        for(int j=0;j<(int)num[i].size();j++) num[i][j].S/=gg;
    }
    bool f=true;
    for(int i=1;i<sz;i++)
    {
        if(!f) break;
        if(num[i].size()!=num[0].size()) {f=false; break;}
        for(int j=0;j<(int)num[i].size();j++)
        {
            if(num[i][j]!=num[0][j])
            {
                f=false;
                break;
            }
        }
    }
    if(!f) puts("0");
    else
    {
        int ans=0;
        for(int i=1;1LL*i*i<=g;i++)
        {
            if(g%i) continue;
            ans++; if(1LL*i*i!=g) ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}