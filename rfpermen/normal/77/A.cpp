#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,a,b,c,x,y,z,ans,cnt,hit;
vector<int> gs;
bool v[8][8];
map<string,int> m;
string s,t;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    m["Anka"] = 1, m["Chapay"] = 2, m["Cleo"] = 3, m["Troll"] = 4;
    m["Snowy"] = 5, m["Dracul"] = 6, m["Hexadecimal"] = 7;
    cin>>n;
    while(n--){
    	cin>>s>>t>>t;
    	v[m[s]][m[t]] = 1;
	}
	cin>>a>>b>>c;
	ans = 1e9;
	int tmp;
	rep(i,1,7)gs.pb(i);
	do {
		rep(i,0,4)rep(j,i+1,5){
			x = a/(i+1), y = b/(j-i), z = c/(6-j);
			cnt = 0;
			rep(I,0,i)rep(J,0,i)cnt+=v[gs[I]][gs[J]];
			rep(I,i+1,j)rep(J,i+1,j)cnt+=v[gs[I]][gs[J]];
			rep(I,j+1,6)rep(J,j+1,6)cnt+=v[gs[I]][gs[J]];
			tmp = max(x,max(y,z))-min(x,min(y,z));
			if(tmp<ans)ans = tmp, hit = cnt;
			else if(tmp==ans)hit = max(hit,cnt);
		}
	}while(next_permutation(all(gs)));
	cout<<ans<<' '<<hit<<endl;
	return 0;
}