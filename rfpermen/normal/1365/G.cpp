#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 1000+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],id;
ll res[15],ans;
vector<int> q;

ll que(){
	if(q.empty())return 0;
	ll ret;
	cout<<"? "<<q.size();
	for(auto i:q)cout<<' '<<i;
	cout<<endl;
	cin>>ret;
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(5);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,100000){
    	if(id==n)break;
    	if(__builtin_popcount(i)==6)x[++id] = i;
	}
	rep(i,0,12){
		q.clear();
		rep(j,1,n)if(x[j]&(1<<i))q.pb(j);
		res[i] = que();
	}
	cout<<"!";
	rep(i,1,n){
		ans = 0;
		rep(j,0,12)if((x[i]&(1<<j))==0)ans|= res[j];
		cout<<' '<<ans;
	}
	cout<<endl;
	return 0;
}