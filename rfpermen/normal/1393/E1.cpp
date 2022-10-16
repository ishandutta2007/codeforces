#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,mn,sz[MAX];
string s[MAX],t[MAX];
vector<int> dp[MAX];

int f(int nw,int ls){
	if(nw>n)return 1;
	if(dp[nw][ls]!=-1)return dp[nw][ls];
	
	ll ret = 0;
	string a = s[nw-1];
	if(ls)a.erase(a.begin()+ls-1);
	if(s[nw]>=a)ret = f(nw+1,0);
	
	mn = min(a.size(),t[nw].size());
	int x[mn+3];
	if(a.size()==mn)x[mn] = 1;
	else x[mn] = -1;
	
	rap(i,mn-1,0){
		if(a[i]==t[nw][i])x[i] = x[i+1];
		else x[i] = (a[i]<t[nw][i] ? 1 : -1);
	}
	
	a.pb('0');
	asd(i,0,sz[nw]){
		if(x[i]==1)ret+= f(nw+1,i+1);
		
		if(a[i]<s[nw][i]){
			asd(j,i+1,sz[nw])ret+= f(nw+1,j+1);
			break;
		}
		else if(a[i]>s[nw][i])break;
	}
	return dp[nw][ls] = ret%MOD;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s[i];
    	t[i] = s[i];
    	t[i].erase(t[i].begin());
    	sz[i] = s[i].size();
    	rep(j,0,s[i].size())dp[i+1].pb(-1);
	}
	dp[1].pb(-1);
	cout<<f(1,0)<<endl;
    return 0;
}