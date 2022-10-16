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

int sc[MAX][27],tc[MAX][27],n;
string s,t;

bool f(int a,int b,int k){
	if(k&1){
		for(int i = 0; i<k; ++i)if(s[a+i]!=t[b+i])return false;
		return true;
	}
	int ma = a+(k>>1)-1, mb = b+(k>>1)-1, ra = a+k-1, rb = b+k-1;
	rep(i,0,25){
		if(sc[ma][i]-sc[a-1][i]!=tc[mb][i]-tc[b-1][i] || sc[ra][i]-sc[ma][i]!=tc[rb][i]-tc[mb][i])break;
		if(i==25 && f(a,b,k>>1) && f(ma+1,mb+1,k>>1))return true;
	}
	rep(i,0,25){
		if(sc[ra][i]-sc[ma][i]!=tc[mb][i]-tc[b-1][i] || sc[ma][i]-sc[a-1][i]!=tc[rb][i]-tc[mb][i])break;
		if(i==25 && f(ma+1,b,k>>1) && f(a,mb+1,k>>1))return true;
	}
	return false;
}

int main(){
//	cout<<fixed<<setprecision(5);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    n = s.size();
    s = 'o'+s, t = 'o'+t;
    rep(i,1,n){
    	rep(j,0,25)sc[i][j] = sc[i-1][j], tc[i][j] = tc[i-1][j];
    	sc[i][s[i]-'a']++;
    	tc[i][t[i]-'a']++;
	}
	rep(i,0,25)if(sc[n][i]!=tc[n][i])return cout<<"NO\n",0;
	
    cout<<(f(1,1,n) ? "YES" : "NO")<<endl;
	return 0;
}