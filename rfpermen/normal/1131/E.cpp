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
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n;
ll a,b,c,mx,ans,nw;
string s[MAX];

int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>s[i];
    for(char tgt = 'a'; tgt<='z'; ++tgt){
    	nw = 0;
    	rep(i,1,n){
    		a = b = c = mx = 0;
    		reverse(all(s[i]));
    		for(char j:s[i]){
    			if(j!=tgt)break;
    			++a;
			}
			reverse(all(s[i]));
    		for(char j:s[i]){
    			if(j!=tgt)break;
    			++b;
			}
			for(char j:s[i]){
    			if(j!=tgt)c = 0;
    			else ++c, mx = max(c,mx);
			}
//			db(a);
			
			if(mx==s[i].size())nw = min(MOD,nw+(nw+1)*mx);
			else nw = max(nw ? a+b+1 : 0,mx);
		}
		ans = max(ans,nw);
	}
	cout<<ans<<endl;
	return 0;
}