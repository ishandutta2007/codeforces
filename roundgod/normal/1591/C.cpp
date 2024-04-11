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
vector<int> pos,neg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        pos.clear(); neg.clear();
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x>=0) pos.push_back(x); else neg.push_back(-x);
        }
        sort(pos.begin(),pos.end()); sort(neg.begin(),neg.end());
        ll ans=0;
        int last=0;
        for(int i=(int)pos.size()-1;i>=0;i-=k) 
        {
            ans+=pos[i];
            last=max(last,pos[i]);
        }
        for(int i=(int)neg.size()-1;i>=0;i-=k) 
        {
            ans+=neg[i];
            last=max(last,neg[i]);
        }
        printf("%lld\n",2*ans-last);
    }
    return 0;
}