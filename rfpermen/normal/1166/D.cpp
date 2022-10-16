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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int c,d;
inline bool cek(ll a,ll b){
	c = d = 0;
	while(a)c++, a/=10;
	while(b)d++, b/=10;
	if(c+d>18)return false;
	return true;
}

ll q,k,a,b,x,sz,upd, le,ri,mid;
vector<ll> v,tmp;


int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
    	cin>>a>>b>>k;
    	if(a==b){cout<<"1 "<<a<<endl; continue;}
    	else if(a+k>=b){cout<<"2 "<<a<<" "<<b<<endl; continue;}
    	else {
    		v.clear();
    		v.pb(a);
    		x = a+1;
    		while(x<=b)v.pb(x), x = x<<1;
//    		for(auto i:v)cout<<i<<" "; cout<<endl;
    		if(v.empty()){cout<<"-1"; continue;}
    		sz = v.size()-1;
    		rep(i,1,sz){
    			if(v.back()==b)break;
    			le = 2, ri = k, upd = 0;
    			while(le<=ri){
    				mid = le+ri>>1;
    				if(cek(mid-1,(1ll<<max(0ll,sz-i-1)))&&v.back()+(mid-1)*(1ll<<max(0ll,sz-i-1))<=b)le = mid+1, upd = mid;
    				else ri = mid-1;
				}
				if(upd){
					x = 0;
					rep(j,0,i-1)x+=v[j];
					v[i] = x+upd;
					x+= x+upd+1;
    				rep(j,i+1,sz)v[j] = x, x<<=1;
				}
			}
			if(v.back()==b){
				cout<<sz+1;
				for(auto i:v)cout<<' '<<i;
				cout<<endl;
				x = a;
				rep(i,1,sz){
					if(x==v[i]||x+k<v[i])return 1;
					x+=v[i];
				}
			}
			else cout<<"-1\n";
		}
	}
	return 0;
}