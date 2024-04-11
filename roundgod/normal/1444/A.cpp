#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,q;
ll p;
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&p,&q);
        if(p%q) printf("%lld\n",p);
        else
        {
            v.clear();
            for(int i=2;i*i<=q;i++)
            {
                if(q%i) continue;
                int cnt=0;
                while(q%i==0) q/=i,cnt++; 
                v.push_back(P(i,cnt));
            }
            if(q>1) v.push_back(P(q,1));
            ll ans=0;
            for(auto pi:v)
            {
                int cnt=pi.S,val=pi.F;
                int cc=0;
                ll tmp=p;
                while(tmp%val==0) tmp/=val,cc++;
                ll res=p;
                for(int i=0;i<max(0,cc-cnt+1);i++) res/=val;
                ans=max(ans,res);
            }
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}