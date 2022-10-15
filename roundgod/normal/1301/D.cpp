#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,string> P;
int T,n,m,k,tot;
vector<P> v;
vector<P> ans;
void solve(int k)
{
    if(k>4*n*m-2*n-2*m) puts("NO");
    else
    {
        puts("YES");
        for(auto p:v)
        {
            if(p.F*(int)p.S.size()<=k)
            {
                k-=p.F*(int)p.S.size();
                ans.push_back(p);
            }
            else
            {
                int need=k/(int)p.S.size();
                k-=need*(int)p.S.size();
                if(need) ans.push_back(P(need,p.S));
                if(k) ans.push_back(P(1,p.S.substr(0,k)));
                k=0;
            }
            if(!k) break;
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) cout<<p.F<<' '<<p.S<<endl;
    }
    
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(m>1) v.push_back(P(m-1,"R"));
    if(m>1) v.push_back(P(m-1,"L"));
    for(int i=1;i<=n-1;i++)
    {
        v.push_back(P(1,"D"));
        if(m>1) v.push_back(P(m-1,"RUD"));
        if(m>1) v.push_back(P(m-1,"L"));
    }
    if(n>1) v.push_back(P(n-1,"U"));
    solve(k);
    return 0;
}