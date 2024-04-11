#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,z[15],id,sz,cnt[3],rem;
string s,t,ans;
bool x[3][3],st;
vector<int> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s>>t;
    if(s[0]!=s[1]&&t[0]!=t[1]){
    	if(s[0]==t[0]&&s[1]!=t[1]){
	    	rep(i,1,n)ans.pb(t[1]);
	    	rep(i,1,n)ans.pb(s[1]);
	    	rep(i,1,n)ans.pb(s[0]);
	    	return cout<<"YES\n"<<ans<<endl,0;
		}
		else if(s[0]!=t[0]&&s[1]==t[1]){
	    	rep(i,1,n)ans.pb(s[1]);
	    	rep(i,1,n)ans.pb(s[0]);
	    	rep(i,1,n)ans.pb(t[0]);
	    	return cout<<"YES\n"<<ans<<endl,0;
		}
	}
    
    x[s[0]-'a'][s[1]-'a'] = x[t[0]-'a'][t[1]-'a'] = 1;
    if(n==1){
    	rep(i,0,2)v.pb(i);
    	do {
    		st = 1;
    		rep(i,1,2)if(x[v[i-1]][v[i]]){
    			st = 0;
    			break;
			}
			if(st)break;
		}while(next_permutation(all(v)));
		if(st)for(auto i:v)ans.pb(i+'a');
	}
	else if(n==2){
    	rep(i,0,2)rep(j,1,2)v.pb(i);
    	do {
    		st = 1;
    		rep(i,1,5)if(x[v[i-1]][v[i]]){
    			st = 0;
    			break;
			}
			if(st)break;
		}while(next_permutation(all(v)));
		if(st)for(auto i:v)ans.pb(i+'a');
	}
	else if(n==3){
    	rep(i,0,2)rep(j,1,3)v.pb(i);
    	do {
    		st = 1;
    		rep(i,1,8)if(x[v[i-1]][v[i]]){
    			st = 0;
    			break;
			}
			if(st)break;
		}while(next_permutation(all(v)));
		if(st)for(auto i:v)ans.pb(i+'a');
	}
	else {
		rem = n%2;
    	rep(i,0,2)rep(j,1,2)v.pb(i);
    	do {
    		if(rem){
    			rep(i,0,2)cnt[i] = 0;
    			rep(i,0,2)++cnt[v[i]];
    			if(cnt[0]!=1||cnt[1]!=1||cnt[2]!=1)continue;
			}
    		st = 1;
    		id = 0;
    		rep(i,0,5)z[++id] = v[i];
    		rep(i,0,2)z[++id] = v[i];
    		rep(i,2,id)if(x[z[i-1]][z[i]]){st = 0; break;}
			if(st)break;
		}while(next_permutation(all(v)));
		if(st){
			sz = n/2;
			rep(j,1,sz)for(auto i:v)ans.pb(i+'a');
			sz = (n%2)*3-1;
			rep(i,0,sz)ans.pb(v[i]+'a');
		}
		else {
			v.clear();
			rep(i,0,2)rep(j,1,3)v.pb(i);
	    	do {
	    		if(rem==1){
	    			rep(i,0,2)cnt[i] = 0;
	    			rep(i,0,2)++cnt[v[i]];
	    			if(cnt[0]!=1||cnt[1]!=1||cnt[2]!=1)continue;
				}
				else if(rem==2){
	    			rep(i,0,2)cnt[i] = 0;
	    			rep(i,0,5)++cnt[v[i]];
	    			if(cnt[0]!=2||cnt[1]!=2||cnt[2]!=2)continue;
				}
	    		st = 1;
	    		id = 0;
	    		rep(i,0,8)z[++id] = v[i];
	    		rep(i,0,2)z[++id] = v[i];
	    		rep(i,2,id)if(x[z[i-1]][z[i]]){st = 0; break;}
				if(st)break;
			}while(next_permutation(all(v)));
			if(st){
				sz = n/3;
				rep(j,1,sz)for(auto i:v)ans.pb(i+'a');
				sz = (n%3)*3-1;
				rep(i,0,sz)ans.pb(v[i]+'a');
			}
		}
	}
	if(ans.empty())return 1;
	else cout<<"YES\n"<<ans<<endl;
	return 0;
}