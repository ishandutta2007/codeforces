#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=1e3+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};
ll n,ans;
map<string,int> a,b;
string s;
int main(){
    //cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>s, a[s]++;
    rep(i,1,n)cin>>s, b[s]++;
    ans=abs(a["S"]-b["S"])+abs(a["XS"]-b["XS"])+abs(a["XXS"]-b["XXS"])+abs(a["XXXS"]-b["XXXS"])+abs(a["L"]-b["L"])
    +abs(a["XL"]-b["XL"])+abs(a["XXL"]-b["XXL"])+abs(a["XXXL"]-b["XXXL"])+abs(a["M"]-b["M"]);
    cout<<ans/2<<endl;
    return 0;
}