#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mod=998244353;
typedef vector<vector<int> >mat;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(ll)x*y%mod;
}
inline mat operator*(mat x,mat y)
{
    int n=x.size();
    int m=y.size();
    int r=y[0].size();
    mat ret;
    ret.resize(n);
    for(auto&t:ret)
        t.resize(r,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<r;k++)
                ret[i][k]=add(ret[i][k],mul(x[i][j],y[j][k]));
    return ret;
}
inline mat pw(mat x,int y)
{
    int n=x.size();
    mat ret;
    ret.resize(n);
    for(int i=0;i<n;i++)
    {
        ret[i].resize(n,0);
        ret[i][i]=1;
    }
    while(y>0)
    {
        if(y%2==1)
            ret=ret*x;
        x=x*x;
        y/=2;
    }
    return ret;
}
vector<int>adj[105];
int main()
{
    int n,m2,k;
    cin>>n>>m2>>k;
    if(k<3)
        return cout<<0<<endl,0;
    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    mat d;
    d.resize(n*2);
    for(auto&t:d)
        t.resize(n*2,0);
    for(int i=0;i<n;i++)
    {
        d[i*2][i*2+1]=sub(1,(int)adj[i].size());
        d[i*2+1][i*2]=1;
        for(int&j:adj[i])
            d[i*2][j*2]=1;
    }
    mat ap=pw(d,k-2);
    mat ad=d;
    for(int i=0;i<n;i++)
        ad[i*2][i*2+1]=sub(0,(int)adj[i].size());
    mat a=ad*ap;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        mat m;
        m.resize(n*2);
        for(auto&t:m)
            t.resize(1);
        m[i*2+1][0]=1;
        for(int&t:adj[i])
            m[t*2][0]=1;
        mat res=a*m;
        ans=add(ans,res[i*2][0]);
    }
    cout<<ans<<endl;
    return 0;
}