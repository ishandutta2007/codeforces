#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a,b,dist,rem;
int get_dist(int x,int y)
{
    return max(y-x,x-y);
}
vector<int> v;
bool check(int x)
{
    for(int i=0;i<x;i++)
    {
        if(v[x-1-i]>=dist+rem-i) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        dist=get_dist(a,b);
        if(a<b) rem=a-1; else rem=n-a;
        sort(v.begin(),v.end());
        int l=0,r=min(get_dist(a,b)-1,(int)v.size())+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}