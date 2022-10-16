#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,a,b,c,x,y,z,sz,mul,res,cnt,ans;
vector<int> f1,f2,f3;
bool st;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    c = a+b;
    x = sqrt(a);
    y = sqrt(b);
    z = sqrt(c);
    rap(i,z,1)if(c%i==0)f1.pb(i);
    rep(i,1,x)if(a%i==0)f2.pb(i);
    rep(i,1,y)if(b%i==0)f3.pb(i);
    for(auto i:f1){
    	for(auto j:f2){
    		if(j<=i && a/j<=c/i){
    			st=1; break;
			}
		}
    	for(auto j:f3){
    		if(j<=i && b/j<=c/i){
    			st=1; break;
			}
		}
    	if(st){
    		ans = i*2+c/i*2;
    		break;
		}
	}
	cout<<ans<<endl;
    return 0;
}