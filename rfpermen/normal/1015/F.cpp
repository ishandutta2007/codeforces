#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 2e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,sz,mem[MAX][MAX],dp[MAX][MAX][MAX],pre[MAX];
bool st;
string s;

ll g(int nw,int st){
	if(!nw)return st==0;
	if(mem[nw][st]!=-1)return mem[nw][st];
	if(!st)return mem[nw][st] = g(nw-1,1);
	return mem[nw][st] = (g(nw-1,st+1) + g(nw-1,st-1))%MOD;
}

ll f(int nw,int st,int pos){
	if(st<0||pos>sz)return 0;
	if(nw==n)return st==0;
	ll &ret = dp[nw][st][pos];
	if(ret!=-1)return ret;
	return ret = (f(nw+1,st+1,(s[pos]=='(' ? pos+1 : pre[pos])) + f(nw+1,st-1,(s[pos]==')' ? pos+1 : pre[pos])))%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s; n<<=1;
    sz = s.size()-1;
    rep(i,1,sz){
    	rap(j,i-1,0){
    		if(s[i]==s[j])continue;
    		st = 1;
    		rep(k,1,j)if(s[i-k]!=s[j-k]){
    			st = 0; break;
			}
			if(st){
				pre[i] = j+1;
				break;
			}
		}
	}
    memset(mem,-1,sizeof mem);
    memset(dp,-1,sizeof dp);
    cout<<(g(n,0) - f(0,0,0) + MOD)%MOD<<endl;
    return 0;
}