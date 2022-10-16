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
#define ff fi.fi
#define fs fi.se
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
const int MAX = 5e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;

int n,q,a,b,c,id,le[MAX*4/block+5][MAX],ri[MAX*4/block+5][MAX],cv[MAX],ov,mn,nw,sza,szb;
string s,S,T,tmp;
map<string,int> hs;
map<int,int> ans[MAX*4];
vector<int> v[MAX*4];

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size(), s = ' '+s;
    rep(i,1,n){
    	tmp.clear();
    	rep(j,0,3)if(i+j<=n){
    		tmp.pb(s[i+j]);
    		if(!hs.count(tmp))hs[tmp] = ++id;
    		v[hs[tmp]].pb(i);
		}
	}
	rep(i,1,id)if(v[i].size()>block){
		cv[i] = ++ov;
		for(int j:v[i])le[ov][j] = ri[ov][j] = j;
		rep(j,1,n)if(!le[ov][j])le[ov][j] = le[ov][j-1];
		rap(j,n,1)if(!ri[ov][j])ri[ov][j] = ri[ov][j+1];
	}
	cin>>q;
	while(q--){
		cin>>S>>T;
		if(!hs.count(S) || !hs.count(T)){cout<<"-1\n"; continue;}
		a = hs[S], b = hs[T];
		sza = S.size(), szb = T.size();
		if(a==b){cout<<sza<<endl; continue;}
		if(0){
			if(cv[a])swap(a,b), swap(sza,szb);
			if(ans[a].count(b)){cout<<ans[a][b]<<endl; continue;}
			mn = n, c = cv[b];
			for(int i:v[a]){
				if(le[c][i])mn = min(mn, max(i+sza,le[c][i]+szb)-le[c][i]);
				if(ri[c][i])mn = min(mn, max(i+sza,ri[c][i]+szb)-i);
			}
		}
		else {
			if(a>b)swap(a,b), swap(sza,szb);
			if(ans[a].count(b)){cout<<ans[a][b]<<endl; continue;}
			mn = n;
			nw = 0;
			for(int i:v[a]){
				while(nw!=v[b].size() && v[b][nw]<i)++nw;
				if(nw==v[b].size())break;
				mn = min(mn,max(i+sza,v[b][nw]+szb)-i);
			}
			nw = 0;
			for(int i:v[b]){
				while(nw!=v[a].size() && v[a][nw]<i)++nw;
				if(nw==v[a].size())break;
				mn = min(mn,max(i+szb,v[a][nw]+sza)-i);
			}
		}
		ans[a][b] = mn;
		cout<<mn<<endl;
	}
	return 0;
}