#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],ans[MAXN],bas[40],pos[40];
vector<P> eve[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        eve[r].push_back(P(l,i));
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i],p=i;
        for(int j=20;j>=0;j--)
        {
            if(x&(1<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x;pos[j]=p;
                    break;
                }
                if(pos[j]<p) swap(bas[j],x),swap(pos[j],p);
                x^=bas[j];
            }
        }
        for(auto p:eve[i])
            for(int j=20;j>=0;j--)
                if(pos[j]>=p.F) ans[p.S]=max(ans[p.S],ans[p.S]^bas[j]);
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}