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
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int x[10],n,nw,a,b;
string s,ans[6] = {"","S","M","L","XL","XXL"};
map<string,int> hs;

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs["S"] = 1,hs["M"] = 2,hs["L"] = 3,hs["XL"] = 4,hs["XXL"] = 5;
    rep(i,1,5)cin>>x[i];
    cin>>n;
    rep(i,1,n){
    	cin>>s;
    	nw = hs[s];
    	if(x[nw])cout<<ans[nw]<<endl, x[nw]--;
    	else {
    		a = -10, b = 10;
    		rap(j,nw,1)if(x[j]){
    			a = j; break;
			}
			rep(j,nw,5)if(x[j]){
    			b = j; break;
			}
			if(abs(nw-a)>=abs(nw-b))cout<<ans[b]<<endl, x[b]--;
			else cout<<ans[a]<<endl, x[a]--;
		}
	}
	return 0;
}