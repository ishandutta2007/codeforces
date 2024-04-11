#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
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

ll n,x[MAX],y,sm,tmp,k,z[MAX];
multiset<ll> s;

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    k = n+1>>1;
    rep(i,1,k)cin>>x[i], sm+= x[i];
    cin>>y;
    if(y>=0)cout<<(sm+(n-k)*y > 0 ? n : -1)<<endl;
    else {
    	rep(i,k+1,n)x[i] = y;
    	k = n-k+1;
    	sm = 0;
    	rep(i,1,k)sm+= x[i];
    	z[k] = sm;
    	s.insert(sm);
		rep(i,k+1,n){
			sm+= x[i]-x[i-k];
			s.insert(sm);
			z[i] = sm;
		}
		sm = 0;
		rap(i,n,k){
			if((*s.begin()) + y*(n-i) > 0)return cout<<k+n-i<<endl,0;
			s.erase(s.find(z[i]));
		}
		cout<<"-1\n";
	}
    return 0;
}