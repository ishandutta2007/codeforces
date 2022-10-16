#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define sf se.fi
#define ss se.se
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
const int MAX = 3e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,nw,lps[MAX],a,b,mx,pg;
string s,t,rt;
bool st[128];
vector<pii> ans;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t>>s;
    rt = t, reverse(all(rt));
    for(auto i:s)st[i] = 1;
    for(auto i:t)st[i] = 0;
    rep(i,0,127)if(st[i])return cout<<"-1\n",0;
    
    n = s.size(), m = t.size(), pg = 0;
    while(pg!=n){
    	nw = lps[pg] = pg;
    	asd(i,pg+1,n){
    		while(nw!=pg && s[nw]!=s[i])nw = lps[nw-1];
    		if(s[nw]==s[i])++nw;
    		lps[i] = nw;
		}
		nw = pg;
		asd(i,0,m){
    		while(nw!=pg && s[nw]!=t[i])nw = lps[nw-1];
    		if(s[nw]==t[i])++nw;
    		if(nw>mx)mx = nw, a = i-nw+pg+2, b = i+1;
    		if(nw==n)break;
		}
		nw = pg;
		asd(i,0,m){
    		while(nw!=pg && s[nw]!=rt[i])nw = lps[nw-1];
    		if(s[nw]==rt[i])++nw;
    		if(nw>mx)mx = nw, a = m-(i-nw+pg+1), b = m-i;
    		if(nw==n)break;
		}
		pg = mx;
		ans.pb({a,b});
	}
	cout<<ans.size()<<endl;
	for(pii i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}