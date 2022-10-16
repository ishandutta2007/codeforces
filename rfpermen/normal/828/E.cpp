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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;
pbds op[4][10][10];

int q,ty,a,n,hs[128],id,l,r,ans;
string s,qu;
char c;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs['C'] = 1, hs['G'] = 2, hs['T'] = 3;
    cin>>s;
    asd(i,0,s.size()){
    	rep(j,1,10)op[hs[s[i]]][j-1][i%j].insert(i);
	}
	cin>>q;
	while(q--){
		cin>>ty;
		if(ty==1){
			cin>>a>>c;
			--a;
			if(s[a]==c)continue;
			rep(i,1,10){
				op[hs[s[a]]][i-1][a%i].erase(a);
				op[hs[c]][i-1][a%i].insert(a);
			}
			s[a] = c;
		}
		else {
			cin>>l>>r>>qu;
			--l, ans = 0;
			n = qu.size();
			asd(i,0,n)ans+= op[hs[qu[i]]][n-1][(i+l)%n].order_of_key(r) - 
							op[hs[qu[i]]][n-1][(i+l)%n].order_of_key(l);
			cout<<ans<<endl;
		}
	}
    return 0;
}