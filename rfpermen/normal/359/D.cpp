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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,x[MAX],ans[MAX],mx,cnt;
pii res[MAX];
vector<pii> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
	rep(i,1,n){
		v.insert(v.begin(),{x[i],i});
		for(int j = 1; j<v.size(); ++j){
			v[j].fi = __gcd(v[j].fi,v[j-1].fi);
			if(v[j].fi==v[j-1].fi)--j, v.erase(v.begin()+j);
		}
		res[i].fi = v[0].se;
	}
	v.clear();
	rap(i,n,1){
		v.insert(v.begin(),{x[i],i});
		for(int j = 1; j<v.size(); ++j){
			v[j].fi = __gcd(v[j].fi,v[j-1].fi);
			if(v[j].fi==v[j-1].fi)--j, v.erase(v.begin()+j);
		}
		res[i].se = v[0].se;
	}
	rep(i,1,n)ans[res[i].fi] = max(ans[res[i].fi],res[i].se-res[i].fi);
	rep(i,1,n)mx = max(ans[i],mx);
	rep(i,1,n)if(ans[i]==mx)++cnt;
	cout<<cnt<<' '<<mx<<endl;
	rep(i,1,n)if(ans[i]==mx)cout<<i<<' ';
    return 0;
}