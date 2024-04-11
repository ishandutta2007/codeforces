#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 10007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,k,x,y,cnt[MAX],ans;
bool st;

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(k==2){
    	rep(i,1,n){
    		cin>>x;
    		y = 1;
    		for(int j = 2; j*j<=x; ++j)if(x%j==0){
    			st = 0;
    			while(x%j==0)x/=j, st^=1;
    			if(st)y*= j;
			}
			++cnt[y*x];
		}
		rep(i,1,100000)ans+= cnt[i]*(cnt[i]-1);
		cout<<ans/2<<endl;
		return 0;
	}
    rep(i,1,n){
    	cin>>x;
    	++cnt[x];
	}
	rep(i,1,100000){
		x = 1;
		rep(j,1,k){
			x*= i;
			if(x>1e10)break;
		}
		if(x>1e10)break;
		for(ll j = 1; j*j<=x; ++j)if(x%j==0){
			y = x/j;
//			if(cnt[j])cout<<cnt[j]<<" "<<cn
			if(j!=y){
				if(y<MAX)ans+= cnt[j]*cnt[y];
			}
			else ans+= cnt[j]*(cnt[j]-1)/2;
		}
	}
	cout<<ans<<endl;
    return 0;
}