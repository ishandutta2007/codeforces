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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
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
const int block = 555;

int tc,n,dp[MAX][2][2][2][2];
string s;

int f(int nw,bool pl1,bool c1,bool ls,bool cls){
	int &ret = dp[nw][pl1][c1][ls][cls];
	if(ret!=-1)return ret;
	ret = MOD;
//	cout<<nw<<' '<<pl1<<' '<<c1<<' '<<ls<<' '<<cls<<endl;
	if(nw==n){
		//ini ujung
		//hadap kiri
		if((cls||ls)&&(pl1||(!pl1&&!c1&&ls)))ret = (int)(s[nw]!='L');
		//hadap kanan
		if((!cls||!ls)&&((pl1&&c1&&!ls)||!pl1))ret = min(ret,(int)(s[nw]!='R'));
	}
	else {
		//coba hadap kiri dulu deh
		if(cls||ls||nw==1)ret = f(nw+1,pl1,c1|(nw==1),0,ls)+(int)(s[nw]!='L');
		//coba hadap kanan
		if(!cls||!ls)ret = min(ret, f(nw+1,pl1,c1,1,ls)+(int)(s[nw]!='R'));
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>s;
//    	n = s.size();
//    	for(char &i:s){
//    		if(i=='R')i = 'L';
//    		else i='R';
//		}
    	rep(i,0,n)mems(dp[i],-1);
    	--n;
//    	db(f(1,0,0,0,0));
//    	db(f(1,1,0,1,0));
    	cout<<min(f(1,0,0,0,0)+(int)(s[0]!='L'),f(1,1,0,1,0)+(int)(s[0]!='R'))<<endl;
	}
    return 0;
}