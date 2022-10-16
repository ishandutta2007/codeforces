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
#define rng() (rand()<<16)|rand()
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
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,en,k,cnt,bit[1<<20],pro[1<<20],fr[25];
ll x[25],pre[1<<20],fl,cek;
string s[55];
double f[25], dv[25], ans;

int main(){
  cout<<fixed<<setprecision(10);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll tmp;
    cin>>k;
    if(k==1)return cout<<"0\n",0;
    rep(i,1,k)cin>>s[i];
    fl = (1ll<<k+1)-2;
    n = s[1].size();
    if(n==1)return cout<<"1\n",0;
    en = (1<<n)-1;
    f[0] = dv[0] = 1.0;
    rep(i,1,n){
    	f[i] = f[i-1]*(double)i;
    	dv[i] = dv[i-1]*(double)(n-i+1);
	}
	rep(i,1,n)f[i]/= dv[i];
    rep(i,0,en)bit[i] = __builtin_popcount(i);
    rep(i,0,19)pro[1<<i] = i;
    
    rep(i,1,k){
    	asd(j,0,n){
    		x[j] = 0;
    		rep(o,1,k)if(s[o][j]==s[i][j])x[j]|= 1ll<<o;
		}
		cek = 1ll<<i;
		pre[0] = fl;
		rep(i,1,en)pre[i] = pre[i^(i&-i)]&x[pro[i&-i]];
		
		rap(o,en,0)if(pre[o]!=cek){
			cnt = 0;
			for(int j = 1; j<en; j<<=1)if(pre[o|j]==cek)++cnt;
			if(cnt)fr[bit[o]+1]+= cnt;
		}
	}
	rep(i,0,n)ans+= fr[i]*f[i];
	cout<<ans/k<<endl;
    return 0;
}