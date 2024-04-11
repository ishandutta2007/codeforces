#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
 
int n,ri;
string s;
vector<int> a,b,tmp;
vector<vector<int>> ans;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s, s = 'o'+s;
	while(1){
		n = s.size()-1;
		ri = n;
		rep(i,1,n){
			if(i>=ri)break;
			if(s[i]=='('){
				while(ri>i&&s[ri]!=')')--ri;
				if(i>=ri)break;
				if(s[ri]!=')')break;
				a.pb(i), b.pb(ri);
				--ri;
			}
		}
		if(a.empty())break;
		tmp.clear();
		for(auto i:a)tmp.pb(i);
		reverse(all(b));
		for(auto i:b)tmp.pb(i);
		a.clear(); b.clear();
		ans.pb(tmp);
		reverse(all(tmp));
		for(auto i:tmp)s.erase(s.begin()+i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		cout<<i.size()<<endl;
		for(auto j:i)cout<<j<<' '; cout<<endl;
	}
    return 0;
}