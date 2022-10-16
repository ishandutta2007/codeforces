#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int tc,w,b,x;
vector<pii> ans,ww;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>b>>w;
    	if(w<b)swap(w,b), x = 1;
    	else x = 0;
    	ans.clear();
    	ww.clear();
    	ww.pb({2,2});
    	rep(i,1,b){
    		ans.pb({1+i*2,2});
    		ans.pb({2+i*2,2});
    		ww.pb({1+i*2,1});
    		ww.pb({1+i*2,3});
		}
		w-=b;
		if(ww.size()<w)cout<<"NO\n";
		else {
			cout<<"YES\n";
			for(auto i:ans)cout<<i.fi<<" "<<i.se+x<<endl;
			w--;
			rep(i,0,w){
				cout<<ww[i].fi<<' '<<ww[i].se+x<<endl;
			}
		}
	}
	return 0;
}