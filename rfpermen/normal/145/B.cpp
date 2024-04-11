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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
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
const int block = 2000;

ll a,b,c,d,tmp,sz;
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d;
    if(min(a,b)<max(c,d) || abs(c-d)>1)return cout<<"-1\n",0;
    if(c==d && max(a,b)<=c)return cout<<"-1\n",0;
    if(c>d){
    	rep(i,1,c)ans.pb(4), ans.pb(7), --a, --b;
	}
	else if(c<d){
		rep(i,1,d)ans.pb(7), ans.pb(4), --a, --b;
	}
	else {
		if(a==c){
			ans.pb(7), --b;
			rep(i,1,c)ans.pb(4), ans.pb(7), --a, --b;
		}
		else {
			ans.pb(4), --a;
			rep(i,1,c)ans.pb(7), ans.pb(4), --a, --b;
		}
	}
	if(ans.back()==4){
		ans.pob();
		rep(i,1,b)ans.pb(7);
		ans.pb(4);
	}
	else rep(i,1,b)ans.pb(7);
	for(auto i:ans){
		cout<<i;
		while(i==4 && a)cout<<4, --a;
	}
	cout<<endl;
    return 0;
}