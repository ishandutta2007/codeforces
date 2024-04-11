#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,a[MAXN];
vector<P> st;
double ans[MAXN];
void add(int u,ll v)
{
    P p=P(u,v);
    int t=(int)st.size();
    while(t>1&&(st[t-1].F-st[t-2].F)*(p.S-st[t-1].S)<=(st[t-1].F-p.F)*(st[t-2].S-st[t-1].S)) 
    {
        st.pop_back();
        t--;
    }
    st.push_back(p);
}
int main()
{
    scanf("%d",&n);
    ll sum=0;
    st.push_back(P(0,0));
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        add(i,sum);
    }
    
    int last=1;
    for(auto p:st)
    {
        double sum=0.0;
        for(int i=last;i<=p.F;i++) sum+=a[i];
        for(int i=last;i<=p.F;i++) ans[i]=sum/(p.F-last+1);
        last=p.F+1;
    }
    for(int i=1;i<=n;i++) printf("%.10f\n",ans[i]);
    return 0;
}