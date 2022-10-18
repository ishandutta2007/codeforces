#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;
ll n,x[N],y[N];
pair<ll,pair<ll,ll> > gg(ll x1, ll y1, ll x2, ll y2)
{
    ll a=y1-y2;
    ll b=x2-x1;
    ll c=-a*x1-b*y1;
    return mp(a,mp(b,c));
}
void g(pair<ll,pair<ll,ll> > pp)
{
    ll a=pp.ff;
    ll b=pp.ss.ff;
    ll c=pp.ss.ss;
    vector<ll> xx,yy;
    for (int i=1; i<=n; i++)
    {
        if (a*x[i]+b*y[i]+c!=0) {xx.pb(x[i]); yy.pb(y[i]);}
    }
    if (xx.size()==0) return;
    if (xx.size()==1) {cout<<"Yes"<<endl; exit(0);}
    pair<ll,pair<ll,ll> > p=gg(xx[0],yy[0],xx[1],yy[1]);
    ll aa=p.ff;
    ll bb=p.ss.ff;
    ll cc=p.ss.ss;
    for (int i=0; i<xx.size(); i++)
        if (aa*xx[i]+bb*yy[i]+cc!=0) return;
    if (aa*b==bb*a) {cout<<"Yes"<<endl; exit(0);}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        x[i]=i;
        cin>>y[i];
    }
    pair<ll,pair<ll,ll> > p=gg(x[1],y[1],x[2],y[2]);
    g(p);
    p=gg(x[1],y[1],x[3],y[3]);
    g(p);
    p=gg(x[2],y[2],x[3],y[3]);
    g(p);
    cout<<"No"<<endl;
}