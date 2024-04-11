#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<ll,ll> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int q,x,y,cnt;
map<string,pii> ans,dp;
map<string,bool> jen;
map<string,vector<string>> isi;
string s,ty,c;

pii solve(string o){
	if(!jen.count(o))return ans[o];
	if(isi[o].empty())return {0,0};
	if(dp.count(o))return dp[o];
	int hit = isi[o].size()-1;
	ll mx = 0, ttl = 0;
	pii res;
	if(jen[o]){//horizontal
		for(auto i:isi[o]){
			res = solve(i);
			mx = max(mx,res.se);
			ttl+= res.fi;
		}
		return dp[o] = {ttl + 2*ans[o].fi + hit*ans[o].se,mx+2*ans[o].fi};
	}
	{//vertikal
		for(auto i:isi[o]){
			res = solve(i);
			mx = max(mx,res.fi);
			ttl+= res.se;
		}
		return dp[o] = {mx+2*ans[o].fi, ttl + 2*ans[o].fi + hit*ans[o].se};
	}
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
    	cin>>ty;
    	x = y = cnt = 0;
    	if(ty=="Widget"){
    		cin>>s;
    		c = "";
    		for(auto i:s){
    			if(i=='('||i==')'||i==',')++cnt;
    			else if(cnt==1)x = x*10 + i-'0';
    			else if(cnt==2)y = y*10 + i-'0';
    			else c.pb(i);
			}
			ans[c] = {x,y};
		}
		else if(ty=="VBox"){
    		cin>>s;
    		ans[s];
    		jen[s];
		}
		else if(ty=="HBox"){
    		cin>>s;
    		ans[s];
    		jen[s] = 1;
		}
		else {
			s = c = "";
			for(auto i:ty){
				if(i=='.')++cnt;
				else if(i=='('){
					if(c=="pack")cnt = 2;
					else if(c=="set_border")cnt = 3;
					else if(c=="set_spacing")cnt = 4;
					c = "";
				}
				else if(i==')')continue;
				else if(cnt==0)s.pb(i);
				else if(cnt==1||cnt==2)c.pb(i);
				else if(cnt==3||cnt==4)x = x*10 + i-'0';
				else return 1;
			}
			if(cnt==2)isi[s].pb(c);
			else if(cnt==3)ans[s].fi = x;
			else ans[s].se = x;
		}
	}
	pii res;
	for(auto i:ans){
		res = solve(i.fi);
		cout<<i.fi<<' '<<res.fi<<' '<<res.se<<endl;
	}
    return 0;
}