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

ll n,a,b,c,x,y,z,sz,T,ans;
string s,t;
map<string,int> m;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    z = x+y;
    while(x){
    	if(x%10)n = n*10 + x%10;
    	x/=10;
	}
	while(n)a = a*10 + n%10, n/=10;
    while(y){
    	if(y%10)n = n*10 + y%10;
    	y/=10;
	}
	while(n)b = b*10 + n%10, n/=10;
    while(z){
    	if(z%10)n = n*10 + z%10;
    	z/=10;
	}
	while(n)c = c*10 + n%10, n/=10;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a+b==c)cout<<"YES";
	else cout<<"NO";
    return 0;
}