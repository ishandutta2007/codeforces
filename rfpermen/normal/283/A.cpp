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
#define endl "\n"
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll q,com,x[MAX],y[MAX],n,a,b,sz;
vector<pii> v;
ll ttl;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q; n=1;
    rep(k,1,q){
    	cin>>com;
    	if(com==1){
    		cin>>a>>b;
    		ttl+=a*b;
    		sz++;
    		v.pb({a,b});
    		if(sz>450){
    			rep(i,1,n)y[i] = 0;
    			while(!v.empty())y[1]+=v.back().se, y[v.back().fi+1]-=v.back().se, v.pob();
    			sz = 0;
    			rep(i,1,n)y[i]+=y[i-1];
    			rep(i,1,n)x[i]+=y[i];
			}
			cout<<(double)ttl/n<<endl;
		}
		else if(com==2){
			cin>>a;
			x[++n] = a;
			ttl+=a;
			cout<<(double)ttl/n<<endl;
		}
		else if(com==3){
			sz--;
			rep(i,0,sz){
				if(n<v[i].fi)ttl-=v[i].se;
				else if(n==v[i].fi){
					ttl-=v[i].se;
					v[i].fi--;
				}
			}
			sz++;
			ttl-=x[n];n--;
			cout<<(double)ttl/n<<endl;
		}
	}
    return 0;
}