#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b,c;
string s;
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        cin>>s;
        v.clear();
        P p=P(s[0]-'0',1);
        for(int i=1;i<n;i++)
        {
            if(s[i]-'0'==p.F) p.S++;
            else
            {
                v.push_back(p);
                p.F=s[i]-'0'; p.S=1;
            }
        }
        v.push_back(p);
       // for(auto p:v) printf("%d %d\n",p.F,p.S);
        int done=0,dzero=0,cnt=0;
        vector<int> tmp;
        for(int i=0;i<(int)v.size();i++)
        {
            P p=v[i];
            if(p.F==0) 
            {
                dzero+=p.S-1;
                if(i==0||i==(int)v.size()-1) cnt++;
                else tmp.push_back(v[i].S);
            }
            else
            {
                done+=p.S-1;
            }
        }
        sort(tmp.begin(),tmp.end());
        ll ans=0;
        int turns=0,inner=0;
        for(int i=0;i<=(int)tmp.size();i++)
        {
            int ones=done+i;
            for(int usel=0;usel<2;usel++)
            {
                if(usel&&v[0].F!=0) continue;
                for(int user=0;user<2;user++)
                {
                    if(user&&(v.size()==1||v.back().F!=0)) continue;
                    int cnt=usel+user;
                    int nturns=(turns+(usel?v[0].S:0)+(user?v.back().S:0));
                    int ninner=(inner+(usel?v[0].S-1:0)+(user?v.back().S-1:0));
                    //printf("nturns=%d ninner=%d\n",nturns,ninner);
                    if(nturns<=ones-1)
                    {
                        int used=min(ones,nturns+dzero-ninner+1);
                        
                        if(used>=1) ans=max(ans,1LL*used*b-1LL*(i+cnt)*c+1LL*(used-1-i-cnt)*a);
                        //printf("used=%d ans=%lld\n",used,ans);
                    }
                    if(nturns<=ones)
                    {
                        int used=min(ones,nturns+dzero-ninner);
                        if(used>=0) ans=max(ans,1LL*used*b-1LL*(i+cnt)*c+1LL*(used-i-cnt)*a);
                        //printf("used=%d ans=%lld\n",used,ans);
                    }
                    if(nturns<=ones)
                    {
                        int used=min(ones,nturns+dzero-ninner-1);
                        if(used>=0) ans=max(ans,1LL*used*b-1LL*(i+cnt)*c+1LL*(used+1-i-cnt)*a);
                        //printf("used=%d ans=%lld\n",used,ans);
                    }
                    //printf("i=%d usel=%d user=%d ans=%lld\n",i,usel,user,ans);
                }
            }
            if(i<(int)tmp.size()) 
            {
                turns+=tmp[i];
                inner+=tmp[i]-1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}