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
#define pllll pair<pll,pll>
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
 
int n,id,hs[128],cnt[69*69],hit[69*69];
bool st;
char z[69];
vector<int> v[69*69],ans,tmp[69*69],cur;

inline void solve(int nw){
	int nx;
	rep(i,0,3843)hit[i] = cnt[i];
	rep(i,0,3843)tmp[i] = v[i];
	cur.clear();
	ans.clear();
	cur.pb(nw);
	while(!cur.empty()){
		if(!tmp[nw].empty()){
			cur.pb(nw);
			nx = tmp[nw].back();
			tmp[nw].pob();
			nw = nx;
		}
		else {
			ans.pb(nw);
			nw = cur.back();
			cur.pob();
		}
	}
	if(ans.size()!=n+1)return;
	reverse(all(ans));
	rep(i,0,n-1){if(ans[i]%62!=ans[i+1]/62)return;}
	cout<<"YES\n";
	for(auto i:ans)cout<<z[i/62];
	cout<<z[ans.back()%62]<<endl;
	exit(0);
}
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,'A','Z')hs[i] = id, z[id] = i, ++id;
    rep(i,'a','z')hs[i] = id, z[id] = i, ++id;
    rep(i,'0','9')hs[i] = id, z[id] = i, ++id;
    cin>>n;
    rep(i,1,n){
    	cin>>s;
    	cnt[hs[s[0]]*id + hs[s[1]]]++;
    	cnt[hs[s[1]]*id + hs[s[2]]]++;
    	v[hs[s[0]]*id + hs[s[1]]].pb(hs[s[1]]*id + hs[s[2]]);
	}
	int a = 0;
	rep(i,0,3843)a+= cnt[i]&1;
	if(a==0)solve(hs[s[0]]*id + hs[s[1]]);
	else if(a==2)rep(i,0,3843)if(cnt[i]&1)solve(i);
	cout<<"NO\n";
    return 0;
}