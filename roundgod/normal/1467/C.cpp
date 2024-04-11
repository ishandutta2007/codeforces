#include<bits/stdc++.h>
#define MAXN 300005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n[3];
vector<int> v[3];
int main()
{
    for(int i=0;i<3;i++) scanf("%d",&n[i]);
    ll sum=0;
    ll res=INF;
    for(int i=0;i<3;i++)
    {
        ll s=0;
        for(int j=0;j<n[i];j++)
        {
            int x;
            scanf("%d",&x); sum+=x; s+=x;
            v[i].push_back(x);
        }
        sort(v[i].begin(),v[i].end());
        res=min(res,s);
    }
    res=min(res,(ll)v[0][0]+v[1][0]);
    res=min(res,(ll)v[0][0]+v[2][0]);
    res=min(res,(ll)v[1][0]+v[2][0]);
    printf("%lld\n",sum-2*res);
    return 0;
}