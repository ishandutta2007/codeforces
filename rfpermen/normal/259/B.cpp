#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<ll,pll>
#define pdd pair<double,double>
//#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int x[3][3],a,b,c;

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,2)rep(j,0,2)cin>>x[i][j];
    rep(i,1,100000){
    	a = i;
    	b = a+x[0][2]-x[2][1];
    	if(a+b != x[1][2]+x[0][2])continue;
    	c = x[0][1]+x[0][2]-b;
    	if(a>0 && b>0 && c>0){
    		x[0][0] = a;
    		x[1][1] = b;
    		x[2][2] = c;
    		rep(i,0,2){
    			rep(j,0,2)cout<<x[i][j]<<" "; cout<<endl;
			}
    		return 0;
		}
	}
    return 0;
}