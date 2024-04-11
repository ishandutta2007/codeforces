#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,k,p,x;
vector<int> a,b;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>p;
    rep(i,1,n){
    	cin>>x;
    	if(x&1)b.pb(x);
    	else a.pb(x);
	}
	k-= p;
	if(b.size()<k || b.size()%2!=k%2 || a.size()+(b.size()-k)/2<p)return cout<<"NO\n",0;
	cout<<"YES\n";
	if(!p){
		asd(i,1,k)cout<<"1 "<<b.back()<<endl, b.pob();
		cout<<a.size()+b.size();
		for(int i:b)cout<<' '<<i;
		for(int i:a)cout<<' '<<i;
		cout<<endl;
	}
	else {
		rep(i,1,k)cout<<"1 "<<b.back()<<endl, b.pob();
		asd(i,1,p){
			if(a.size())cout<<"1 "<<a.back()<<endl, a.pob();
			else cout<<"2 "<<b.back()<<' '<<b[b.size()-2]<<endl, b.pob(), b.pob();
		}
		cout<<a.size()+b.size();
		for(int i:b)cout<<' '<<i;
		for(int i:a)cout<<' '<<i;
		cout<<endl;
	}
	return 0;
}