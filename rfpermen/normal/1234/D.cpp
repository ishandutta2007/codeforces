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
 
int n,q,a,b,ty,id,sz,ans;
char c;
set<int> st[26];
string s;
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>q;
    sz = s.size()-1;
    rep(i,0,sz)st[s[i]-'a'].insert(i);
    while(q--){
    	cin>>ty>>a;
    	if(ty==1){
    		cin>>c;
    		--a;
    		st[s[a]-'a'].erase(a);
    		s[a] = c;
    		st[s[a]-'a'].insert(a);
		}
		else {
			cin>>b;
			--a, --b;
			ans = 0;
			rep(i,0,25){
				auto it = st[i].lower_bound(a);
				if(it==st[i].end())continue;
				if(*it<=b)++ans;
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}