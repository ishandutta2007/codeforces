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
#define endl "\n"
#define usi unsigned short int
const ll MAX=5e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,st,x,z;
vector<int> a,b;

int main(){
	//cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>z;
    	if(z>0)st = 1;
    	else st = 2;
		x+=z;
		if(z>0)a.pb(z);
		else b.pb(-z);
	}
	if(x<0)return cout<<"second",0;
	else if(x>0)return cout<<"first",0;
	else {
		z = max(a.size()-1,b.size()-1);
		rep(i,0,z)if(a[i]>b[i])return cout<<"first",0; else if(a[i]<b[i])return cout<<"second",0;
	}
	if(a.size()>b.size())return cout<<"first",0;
	else if(a.size()<b.size())return cout<<"second",0;
	if(st&1)cout<<"first";
	else cout<<"second";
    return 0;
}