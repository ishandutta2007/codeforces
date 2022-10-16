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

ll ans,fc[MAX],pre[MAX],z[1050],dp[2][MAX],res;
int n,k,id,cnt,x[MAX],tmp;
bool st,nw,ls;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre[0] = fc[0] = 1;
    rep(i,1,100000)fc[i] = (fc[i-1]*i)%MOD, pre[i] = pw(fc[i],MOD-2);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    rep(i,1,n){
		tmp = x[i];
		st = 1;
		while(tmp){
			if(tmp%10!=4 && tmp%10!=7){
				st = 0;
				break;
			}
			tmp/=10;
		}
		if(st){
			if(x[i]!=x[i-1])z[++id]++;
			else z[id]++;
		}
		else ++cnt;
	}
	dp[0][0] = 1;
	nw = 1;
	rep(i,1,id){
		dp[nw][0] = 1;
		rep(j,1,id)dp[nw][j] = (dp[ls][j-1]*z[i] + dp[ls][j])%MOD;
		memset(dp[ls],0,sizeof dp[ls]);
		nw^=1, ls^=1;
	}
    rep(i,0,k){
    	res = cnt-(k-i);
    	if(res<0)continue;
    	res = fc[cnt] * pre[res] % MOD * pre[k-i] % MOD * dp[ls][i] % MOD;
    	ans+= res;
	}
	cout<<ans%MOD<<endl;
    return 0;
}