#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x,y,z=-1,res[MAX];
vector<int> v[MAX];

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cout<<"XOR 1 "<<i<<endl;
    	cin>>x;
    	res[i] = x;
    	v[x].pb(i);
    	if(v[x].size()>1)z = x;
	}
	if(!v[0].empty()){
		cout<<"AND 1 "<<v[0][0]<<endl;
		cin>>x;
		res[1] = x;
	}
	else if(z==-1){
		cout<<"AND 1 "<<v[1][0]<<endl;
		cin>>x;
		cout<<"AND 1 "<<v[2][0]<<endl;
		cin>>y;
		res[1] = x|y;
	}
	else {
		cout<<"AND "<<v[z][0]<<' '<<v[z][1]<<endl;
		cin>>x;
		res[1] = x^z;
	}
	cout<<"! "<<res[1];
	rep(i,2,n)cout<<' '<<(res[1]^res[i]); cout<<endl;
    return 0;
}