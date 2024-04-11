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
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,k,mn,pin,a,b;
pii x[MAX];
vector<int> v;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(n==2)return cout<<"0\n1 1",0;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    mn = x[n].fi + x[n-1].fi - x[2].fi - x[1].fi;
    v.pb(x[n].fi + x[n-1].fi), v.pb(x[3].fi + x[2].fi), v.pb(x[2].fi + x[1].fi + k), v.pb(x[n].fi + x[1].fi + k);
    sort(all(v));
    a = v[3] - v[0];
    v.clear();
    if(n!=3)v.pb(x[n].fi + x[n-1].fi);
	v.pb(x[3].fi + x[1].fi), v.pb(x[2].fi + x[1].fi + k), v.pb(x[n].fi + x[2].fi + k);
    sort(all(v));
    b = v.back() - v[0];
    if(min(a,b)<mn){
    	if(a<b)pin = x[1].se;
		else pin = x[2].se;
		mn = min(a,b);
	}
	cout<<mn<<endl;
	rep(i,1,n)cout<<(i==pin ? 2 : 1)<<' ';
    return 0;
}