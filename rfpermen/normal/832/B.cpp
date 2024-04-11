#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e5+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,sz,id;
string s,t;
bool v[128],st,ad;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(auto i:s)v[i] = 1;
    cin>>s>>n;
    for(auto i:s)if(i=='*')ad = 1;
    while(n--){
    	st = 1, id = -1;
    	cin>>t;
    	if(t.size()==s.size()){
    		for(auto i:s){
    			++id;
    			if(i==t[id])continue;
    			if(i=='?'&&v[t[id]])continue;
    			if(i=='*'&&!v[t[id]])continue;
    			st = 0;
			}
		}
		else if(t.size()==s.size()-1&&ad){
			for(auto i:s){
				if(i=='*')continue;
    			++id;
    			if(i==t[id])continue;
    			if(i=='?'&&v[t[id]])continue;
    			st = 0;
			}
		}
		else if(t.size()>s.size()&&ad){
			sz = t.size();
			for(auto i:s){
				if(i=='*'){
					while(sz>=s.size()){
						++id, sz--;
						if(v[t[id]])st = 0;
					}
					continue;
				}
    			++id;
    			if(i==t[id])continue;
    			if(i=='?'&&v[t[id]])continue;
    			st = 0;
			}
		}
		else st = 0;
		if(st)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}