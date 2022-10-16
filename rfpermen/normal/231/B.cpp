#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,d,m,c;
vector<int> ans;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d>>m;
    if(n&1){
    	if(d<=0)ans.pb(1), d--;
		else ans.pb(min(d,m)), d-=min(d,m);
		n/=2;
		rep(i,1,n){
			c = min(m-1,abs(d));
			if(d<0)c*=-1;
			d-=c;
			ans.pb(1-min(c,0));
			ans.pb(1+max(c,0));
		}
	}
	else {
		n/=2;
		rep(i,1,n){
			c = min(m-1,abs(d));
			if(d<0)c*=-1;
			d-=c;
			ans.pb(1+max(c,0));
			ans.pb(1-min(c,0));
		}
	}
	if(d)return cout<<-1,0;
	for(auto i:ans)cout<<i<<" ";
    return 0;
}