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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

ll x[4],y[4],z[4],ttl,ans,r;
string s;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(auto i:s){
    	if(i=='B')z[1]++;
    	else if(i=='S')z[2]++;
    	else z[3]++;
	}
    rep(i,1,3)cin>>x[i];
    rep(i,1,3)cin>>y[i], ttl+=z[i]*y[i];
    cin>>r;
    while((x[1]&&z[1]) || (x[2]&&z[2]) || (x[3]&&z[3])){
    	if(x[1]>=z[1] && x[2]>=z[2] && x[3]>=z[3]){
    		x[1]-=z[1];
    		x[2]-=z[2];
    		x[3]-=z[3];
    		ans++;
		}
		else {
			rep(i,1,3)if(x[i]<z[i]){
				r-=y[i]*(z[i]-x[i]);
				x[i] = z[i];
			}
			if(r<0)return cout<<ans,0;
		}
	}
	cout<<ans+r/ttl<<endl;
    return 0;
}