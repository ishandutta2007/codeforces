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

ll n,m,k,a,b,c,x,y,z;

int main(){
	cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>x;
    rep(i,2,n){
    	if(!c)k = y;
    	y = x;
    	cin>>x;
    	if(x>=y && (!c || b))continue;
    	if(x>y && c && !b){
    		if(z>x || k>y)c=2;
    		else b = i-1;
    		continue;
		}
    	if(x<y && b)c=2;
    	if(x<y && c)continue;
    	c++, a = i-1, z = y;
	}
	if(c && !b){
		b = n;
		if(k>x)c=2;
	}
	if(!c)cout<<"yes\n1 1\n";
	else if(c==1)cout<<"yes\n"<<a<<" "<<b<<endl;
	else cout<<"no\n";
    return 0;
}