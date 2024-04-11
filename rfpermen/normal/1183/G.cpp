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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int tc,n,z,mx,mn,ans,cnt,bs,tmp;
map<int,pii> m;
pii x[MAX];
bool f;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	m.clear();
    	while(n--){
    		cin>>z>>f;
    		m[z].fi++;
    		m[z].se+=f;
		}
		n = 0;
		for(auto i:m)x[++n] = i.se;
		sort(x+1,x+1+n);
		reverse(x+1,x+1+n);
		ans = cnt = 0;
		mx = 1e9;
		rep(i,1,n){
			mx = min(mx-1,x[i].fi), mn = min(mx,x[i].se), bs = i;
			if(mx<=0)break;
			rep(j,i+1,n){
				if(x[j].fi>=mx){
					tmp = min(mx,x[j].se);
					if(tmp>mn)mn = tmp, bs = j;
				}
				else break;
			}
			if(bs!=i)swap(x[i],x[bs]);
			ans+=mx, cnt+=mn;
		}
		cout<<ans<<' '<<cnt<<endl;
	}
	return 0;
}