#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll tc,n,a,b,x,y,z,tmp,res,sz,id,ls;
set<int> s,vis;
vector<int> ans;
 
int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ans.pb(0);
    rep(i,1,n){
    	cin>>x;
    	if(x<0){
    		x = -x;
			if(!s.count(x))return cout<<"-1\n",0;
			s.erase(x);
			if(s.empty())vis.clear(), ans.pb(i), ++a;
		}
		else {
			if(s.count(x) || vis.count(x))return cout<<"-1\n",0;
			s.insert(x), vis.insert(x);
		}
	}
	if(!s.empty())return cout<<"-1\n",0;
	cout<<a<<endl;
	rep(i,1,a)cout<<ans[i] - ans[i-1]<<' ';
    return 0;
}