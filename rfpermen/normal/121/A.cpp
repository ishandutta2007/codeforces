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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int a,b,ls;
ll ans;
bool st;
vector<ll> v;

void dfs(ll i){
	if(i>4444444444)return;
	v.pb(i);
	if(i==4444444444)return;
	dfs(i*10+4);
	dfs(i*10+7);
	return;
}

int main(){
    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dfs(4), dfs(7);
    sort(v.begin(),v.end());
    cin>>a>>b;
    for(auto i:v){
    	if(a<=i && !st){
    		st = 1;
//    	cout<<i<<endl;
    		if(i<b)ans = (ll)i*(i-a+1);
    		else {
    			ans = (ll)i*(b-a+1); break;
			}
    		ls = i;
    		continue;
		}
		if(st){
//			cout<<ans<<endl;
			if(i>=b){
				ans+=(ll)i*(b-ls); break;
			}
			else ans+=(ll)i*(i-ls);
			ls = i;
		}
	}
    cout<<ans<<endl;
    return 0;
}