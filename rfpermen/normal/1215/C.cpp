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

int a,b,c,d,sz,ls;
string s,t;
vector<pii> ans;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>s>>t;
    for(auto i:s){
    	if(i=='a')++a;
    	else ++b;
	}
    for(auto i:t){
    	if(i=='a')++c;
    	else ++d;
	}
	if((a+c)&1)return cout<<-1,0;
	sz = s.size()-1;
	ls = -1;
	rep(i,0,sz){
		if(s[i]=='a'&&t[i]=='b'){
			if(ls==-1)ls = i;
			else {
				swap(s[ls],t[i]);
				ans.pb({ls,i});
				ls = -1;
			}
		}
	}
	ls = -1;
	rep(i,0,sz){
		if(s[i]=='b'&&t[i]=='a'){
			if(ls==-1)ls = i;
			else {
				swap(s[ls],t[i]);
				ans.pb({ls,i});
				ls = -1;
			}
		}
	}
	ls = -1;
	rep(i,0,sz){
		if(s[i]!=t[i]){
			if(ls==-1)ls = i;
			else {
				swap(s[i],t[i]);
				swap(s[ls],t[i]);
				ans.pb({i,i});
				ans.pb({ls,i});
				ls = -1;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi+1<<' '<<i.se+1<<endl;
	return 0;
}