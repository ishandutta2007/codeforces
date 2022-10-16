#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int ans;
bool st;
string s,t,tmp;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    if(s.size()>t.size())swap(s,t);
    for(auto i:s){
    	tmp.pb(i);
    	if(s.size()%tmp.size()||t.size()%tmp.size())continue;
    	st = 1;
    	for(int j = 0; j<s.size(); j+=tmp.size()){
    		if(!st)break;
    		for(int k = 0; k<tmp.size(); ++k){
    			if(s[j+k]!=tmp[k]){
    				st = 0;
    				break;
				}
			}
		}
    	for(int j = 0; j<t.size(); j+=tmp.size()){
    		if(!st)break;
    		for(int k = 0; k<tmp.size(); ++k){
    			if(t[j+k]!=tmp[k]){
    				st = 0;
    				break;
				}
			}
		}
		ans+=st;
	}
	cout<<ans<<endl;
	return 0;
}