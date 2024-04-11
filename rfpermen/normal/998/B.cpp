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
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};
ll n,x[105],y[2],a,b,ans,tot,sz;
vector<int> v;
int main(){
    //cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>b;
    rep(i,1,n)cin>>x[i];
	rep(i,1,n-1){
		y[x[i]%2]++;
		//cout<<y[0]<<" "<<y[1]<<" "<<x[i]<<" "<<abs(x[i]-x[i+1])<<endl;
		if(y[0]==y[1])v.pb(abs(x[i]-x[i+1]));
	}
	sort(v.begin(),v.end());
	sz=v.size();
	rep(i,0,sz-1){
		//cout<<v[i]<<endl;
		if(tot+v[i]<=b)tot+=v[i], ans++;
	}
	cout<<ans<<endl;
    return 0;
}