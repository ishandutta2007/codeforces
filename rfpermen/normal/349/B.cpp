#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,y[10],z[10];
pii x[10];

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,9)cin>>x[i].fi, x[i].se = i, z[i] = x[i].fi;
    sort(x+1,x+10);
    if(n<x[1].fi)return cout<<-1,0;
    y[x[1].se]=n/x[1].fi;
    n -= n/x[1].fi * x[1].fi;
    rap(i,9,1){
    	rep(j,1,i-1){
    		while(y[j] && n+z[j]>=z[i])n+=z[j]-z[i], y[j]--, y[i]++;
		}
	}
	rap(i,9,1)while(y[i]--)cout<<i;
    return 0;
}