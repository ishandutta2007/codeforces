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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,x,ans,hs[128],res;
string s[1505];
map<ll,int> cnt;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs['S'] = 1, hs['E'] = 2, hs['T'] = 3;
    cin>>n>>x; x--;
    rep(i,1,n){
    	cin>>s[i];
    	res = 0;
    	for(auto &j:s[i]){
    		j = hs[j];
    		res = (res<<2) + j;
		}
		cnt[res]++;
	}
	rep(i,1,n){
		res = 0;
		for(auto j:s[i])res = (res<<2) + j;
		cnt[res]--;
		rep(j,i+1,n){
			res = 0;
			for(auto k:s[j])res = (res<<2) + k;
			cnt[res]--;
			res = 0;
			rep(k,0,x){
				if(s[i][k]==s[j][k])res = (res<<2)+s[i][k];
				else res = (res<<2)+(s[i][k]^s[j][k]);
			}
			ans+= cnt[res];
		}
		rep(j,i+1,n){
			res = 0;
			for(auto k:s[j])res = (res<<2) + k;
			cnt[res]++;
		}
	}
	cout<<ans<<endl;
    return 0;
}