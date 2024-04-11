#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define kn fi.fi
#define ki fi.se
#define ttl se.fi
#define mx se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll x[MAX],y,n,rg,sz;
vector<ll> v;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    y = 1e9;
    rep(i,1,n)cin>>x[i], y = min(x[i],y);
    rep(i,1,n)if(x[i]==y)v.pb(i);
    sz = v.size()-1;
    v.pb(v[0]+n);
    rg = v[1]-v[0];
    rep(i,1,sz)rg = max(rg,v[i+1]-v[i]);
    cout<<y*n+rg-1;
    return 0;
}