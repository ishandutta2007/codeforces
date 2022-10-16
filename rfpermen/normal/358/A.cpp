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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,k,a,b,c,x[1005],y,z,sz,T,pv;
string s,t;
bool v[55][55];

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n<=2)return cout<<"no",0;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	rep(j,2,i-1){
    		if(x[j-1]<x[i-1] && x[j]>x[i-1] && (x[j-1]>x[i] || x[j]<x[i]))return cout<<"yes",0;
    		if(x[j-1]>x[i-1] && x[j]<x[i-1] && (x[j-1]<x[i] || x[j]>x[i]))return cout<<"yes",0;
    		if(x[j-1]<x[i] && x[j]>x[i] && (x[j-1]>x[i-1] || x[j]<x[i-1]))return cout<<"yes",0;
    		if(x[j-1]>x[i] && x[j]<x[i] && (x[j-1]<x[i-1] || x[j]>x[i-1]))return cout<<"yes",0;
		}
	}
	cout<<"no";
    return 0;
}