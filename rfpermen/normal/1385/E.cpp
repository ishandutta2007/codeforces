#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int tc,n,m,a,b,cnt[MAX],id,num[MAX];
bool ty;
vector<int> v[MAX];
vector<pii> e;
stack<int> s;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n)cnt[i] = 0, v[i].clear();
    	e.clear();
    	rep(i,1,m){
    		cin>>ty>>a>>b;
    		if(ty)v[a].pb(b), cnt[b]++;
    		else e.pb({a,b});
		}
		rep(i,1,n)if(!cnt[i])s.push(i);
		id = 0;
		while(!s.empty()){
			a = s.top(); s.pop();
			num[a] = ++id;
			for(int i:v[a]){
				cnt[i]--;
				if(!cnt[i])s.push(i);
			}
		}
		if(id!=n)cout<<"NO\n";
		else {
			cout<<"YES\n";
			rep(i,1,n)for(int j:v[i])cout<<i<<' '<<j<<endl;
			for(pii i:e){
				if(num[i.fi]<num[i.se])cout<<i.fi<<' '<<i.se<<endl;
				else cout<<i.se<<' '<<i.fi<<endl;
			}
		}
	}
	return 0;
}