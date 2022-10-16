#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int st,a;
string s,t;
map<string,int> ty;
bool ad;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ty["soil"] = 1, ty["rte"] = 2, ty["sitini"] = 3;
    ty["alail"] = 4, ty["arte"] = 5, ty["setini"] = 6;
    cin>>s;
    reverse(all(s));
    t = "";
    for(auto i:s){
    	t.pb(i);
    	if(t.size()>6)break;
    	if(ty.find(t)!=ty.end()){
    		st = ty[t];
    		break;
		}
	}
	if(!st)return cout<<"NO\n",0;
    while(cin>>s){
    	if(!ad){
    		if(st==6||st==3)return cout<<"NO\n",0;
		}
    	ad = 1;
	    reverse(all(s));
	    t = "", a = 0;
	    for(auto i:s){
	    	t.pb(i);
	    	if(t.size()>6)break;
	    	if(ty.find(t)!=ty.end()){
	    		a = ty[t];
	    		break;
			}
		}
		if(!a||(st-1)/3!=(a-1)/3||st>a||a-st>1||(st%3==2&&st==a))return cout<<"NO\n",0;
		st = a;
	}
	if(!ad||st%3!=1)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}