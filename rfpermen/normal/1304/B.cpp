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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e4+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int sz,n;
string s;
vector<string> v,x,y,z;
bool st;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>sz;
    --sz;
    rep(i,1,n){
    	cin>>s;
		v.pb(s);
	}
    st = 1;
    while(st&&!v.empty()){
    	st = 0;
    	n = v.size()-1;
    	rep(i,0,n){
    		rep(j,i+1,n){
    			reverse(all(v[j]));
    			if(v[i]==v[j]){
    				reverse(all(v[j]));
    				x.pb(v[i]);
    				y.pb(v[j]);
    				v.erase(v.begin()+j);
    				v.erase(v.begin()+i);
    				st = 1;
    				break;
				}
				else reverse(all(v[j]));
			}
			if(st)break;
		}
	}
	for(auto i:v){
		st = 1;
    	rep(j,0,sz/2)if(i[j]!=i[sz-j]){
    		st = 0;
    		break;
		}
		if(st){
			z.pb(i);
			break;
		}
	}
	cout<<(sz+1)*(x.size()+y.size()+z.size())<<endl;
	for(auto i:x)cout<<i;
	for(auto i:z)cout<<i;
	reverse(all(y));
	for(auto i:y)cout<<i;
    return 0;
}