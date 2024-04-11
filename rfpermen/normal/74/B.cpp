#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,k,sz,dp[205][55][55][2];
string s,mv;

int f(int pos,int a,int b,bool dir){
	if(a==b)return pos-1;
	if(pos>sz)return 1e9;
	int &ret = dp[pos][a][b][dir];
	if(ret!=-1)return ret;
	if(dir==1&&b==n)dir = 0;
	else if(dir==0&&b==1)dir = 1;
	int tmp = b;
	if(dir)++b;
	else --b;
	if(mv[pos]=='0'){
		rep(i,max(1,a-1),min(n,a+1))if(i!=tmp)ret = max(ret,f(pos+1,i,b,dir));
	}
	else {
		rep(i,1,n)ret = max(ret,f(pos+1,i,b,dir));
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    cin>>s>>s>>mv;
    sz = mv.size(), mv = '0'+mv;
    memset(dp,-1,sizeof dp);
    if(f(1,m,k,(s=="tail"))>sz)cout<<"Stowaway\n";
    else cout<<"Controller "<<f(1,m,k,s=="tail")<<endl;
    return 0;
}