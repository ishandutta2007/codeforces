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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,x[MAX],y[MAX],z[MAX],tmp[MAX],mn;
bool a[MAX],b[MAX],ans;
vector<ll> v;

bool cek(){
	ll mn;
	asd(i,1,v.size()){
		mn = min(v[i-1],v[i]);
		v[i-1]-= mn, v[i]-= mn;
		if(v[i-1])return false;
	}
	if(v.back())return false;
	return true;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool st,res;
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)cin>>x[i], tmp[i] = x[i];
    	y[1] = x[1];
    	rep(i,2,n){
    		if(a[i-1]){
    			a[i] = 1;
    			continue;
			}
    		mn = min(tmp[i-1],tmp[i]);
    		if(tmp[i-1]!=mn)a[i] = 1;
    		else a[i] = 0;
    		tmp[i]-= mn;
    		y[i] = tmp[i];
		}
		rep(i,1,n)tmp[i] = x[i];
		
		b[n] = 0, z[n] = x[n];
		rap(i,n-1,1){
			if(b[i+1]){
				b[i] = 1;
				continue;
			}
			mn = min(tmp[i+1],tmp[i]);
			if(tmp[i+1]!=mn)b[i] = 1;
			else b[i] = 0;
    		tmp[i]-= mn;
    		z[i] = tmp[i];
		}
		
//		rep(i,1,n)cout<<y[i]<<' '; cout<<endl;
//		rep(i,1,n)cout<<z[i]<<' '; cout<<endl;
		
		ans = 0;
		if(!a[n] && !y[n])ans = 1;
		
		if(!ans)rep(i,2,n)if(!(i!=2 && a[i-2]) && !(i!=n && b[i+1])){
			v.clear();
			swap(x[i-1],x[i]);
			if(i!=2)v.pb(y[i-2]);
			v.pb(x[i-1]);
			v.pb(x[i]);
			if(i!=n)v.pb(z[i+1]);
			if(cek()){
				ans = 1;
				break;
			}
			swap(x[i-1],x[i]);
		}
		
		cout<<(ans ? "YES\n" : "NO\n");
	}
    return 0;
}