#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,k,id,ans;
string s;
struct trie{
	int nx[26],res;
}tr[MAX];

inline void ins(){
	int nw = 0;
	for(char i:s){
		i-='a';
		if(!tr[nw].nx[i])tr[nw].nx[i] = ++id;
		nw = tr[nw].nx[i];
	}
	return;
}

int dfs(int nw){
	bool st = 0;
	rep(i,0,25)if(tr[nw].nx[i]){
		st = 1;
		ans = dfs(tr[nw].nx[i]);
		tr[nw].res|=3^ans;
	}
	if(!st)tr[nw].res = 2;
	return tr[nw].res;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>s;
    	ins();
	}
	ans = dfs(0);
	if(ans==3)cout<<"First\n";
	else if(ans==2 || ans==0)cout<<"Second\n";
	else if(ans==1)cout<<(k&1 ? "First\n" : "Second\n");
	return 0;
}