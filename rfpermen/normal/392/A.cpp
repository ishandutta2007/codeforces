#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<pll,ll>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0};
const int dc[]={0,1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,N,x,y,ans;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("rekreasi_7.in", "r", stdin);
//	freopen("rekreasi_7.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==0)return cout<<"1\n",0;
    N = n*n;
    y = n;
    while(y!=0){
    	++ans;
    	++x;
    	if(x*x+y*y<=N)continue;
    	--y;
    	if(x*x+y*y<=N)continue;
    	--x;
	}
	cout<<ans*4<<endl;
	return 0;
}