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
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,f[MAX],ans,cnt,tmp;
pii x[MAX];
bool st;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = 1;
    rep(i,1,300000)f[i] = f[i-1]*i%MOD;
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].se;
    sort(x+1,x+1+n);
    tmp = 1;
    rep(i,1,n){
    	swap(x[i].fi,x[i].se);
    	if(x[i].se!=x[i-1].se){
    		tmp = tmp*f[cnt]%MOD;
    		cnt = 0;
		}
		++cnt;
	}
	ans = f[n]-tmp*f[cnt]%MOD;
    sort(x+1,x+1+n);
    tmp = 1, cnt = 0;
    rep(i,1,n){
    	if(x[i].fi!=x[i-1].fi){
    		tmp = tmp*f[cnt]%MOD;
    		cnt = 0;
		}
		++cnt;
	}
	ans-= tmp*f[cnt]%MOD;
	st = 1;
	rep(i,1,n)if(x[i-1].se>x[i].se){
		st = 0; break;
	}
	if(st){
		tmp = 1, cnt = 0;
		rep(i,1,n){
			if(x[i]!=x[i-1]){
	    		tmp = tmp*f[cnt]%MOD;
	    		cnt = 0;
			}
			cnt++;
		}
		ans+= tmp*f[cnt]%MOD;
	}
	cout<<(ans%MOD + MOD)%MOD<<endl;
    return 0;
}