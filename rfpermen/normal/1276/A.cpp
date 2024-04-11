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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,cnt,id,pf[MAX];
char ls;
string s;
pair<char,int> x[MAX];
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>s;
    	rep(i,1,id)x[i] = {0,0};
    	ls = s[0], cnt = id = 0, s.pb(' ');
    	for(auto i:s){
    		if(i==ls)++cnt;
    		else {
    			if((ls=='w'||ls=='n')&&cnt!=1)ls = ' ';
    			x[++id] = {ls,cnt}, ls = i, cnt = 1, pf[id] = pf[id-1] + x[id-1].se;
			}
		}
		ans.clear();
		rep(i,1,id){
			if(x[i].fi=='o'&&x[i+1].fi=='n'&&x[i+2].fi=='e'){
				if(x[i].se<x[i+1].se&&x[i].se<x[i+2].se){
					rep(j,1,x[i].se)ans.pb(pf[i]+j);
				}
				else if(x[i+1].se<x[i+2].se){
					rep(j,1,x[i+1].se)ans.pb(pf[i+1]+j);
				}
				else rep(j,1,x[i+2].se)ans.pb(pf[i+2]+j);
			}
			else if(x[i].fi=='t'&&x[i+1].fi=='w'&&x[i+2].fi=='o'){
				if(x[i+3].fi=='n'&&x[i+4].fi=='e'&&
					x[i+2].se<min(x[i].se,x[i+1].se)+min(x[i+3].se,x[i+4].se)){
					rep(j,1,x[i+2].se)ans.pb(pf[i+2]+j);
					i+=3;
				}
				else {
					if(x[i].se<x[i+1].se&&x[i].se<x[i+2].se){
						rep(j,1,x[i].se)ans.pb(pf[i]+j);
					}
					else if(x[i+1].se<x[i+2].se){
						rep(j,1,x[i+1].se)ans.pb(pf[i+1]+j);
					}
					else rep(j,1,x[i+2].se)ans.pb(pf[i+2]+j);
				}
			}
		}
		cout<<ans.size()<<endl;
		for(auto i:ans)cout<<i<<' '; cout<<endl;
	}
    return 0;
}