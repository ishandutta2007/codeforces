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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const int MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

ll n,m,x[MAX][MAX],mn,up,dw,gs,r[MAX],c[MAX];

int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j], mn = max(mn,x[i][j]);
    ++mn;
    rep(i,1,m)c[i] = x[1][i];
    rep(i,2,n){
    	up = dw = -1;
    	rep(j,1,m){
    		if(x[1][j]<=x[i][j]){
    			if(up==-1)up = x[i][j] - x[1][j];
    			else if(up!=x[i][j] - x[1][j])return cout<<"NO\n",0;
			}
			else {
				if(dw==-1)dw = x[1][j] - x[i][j];
    			else if(dw!=x[1][j] - x[i][j])return cout<<"NO\n",0;
			}
		}
//		cout<<">> "<<up<<' '<<dw<<endl;
		if(up==-1)r[i] = -dw;
		else {
			r[i] = up;
			if(dw!=-1){
				if(!gs)gs = up+dw;
				if(gs!=up+dw||gs<mn)return cout<<"NO\n",0;
			}
		}
	}
//	db("tes");
//	db(gs);
	if(!gs)gs = mn;
	rep(i,1,n)if(r[i]<0)r[i]+=gs;
	rep(i,1,n)rep(j,1,m)if((r[i]+c[j])%gs!=x[i][j])return cout<<"NO\n",0;
	cout<<"YES\n";
	cout<<gs<<endl;
	rep(i,1,n)cout<<r[i]<<' '; cout<<endl;
	rep(i,1,m)cout<<c[i]<<' '; cout<<endl;
    return 0;
}