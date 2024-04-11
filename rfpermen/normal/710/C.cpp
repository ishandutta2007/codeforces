#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,m,x,y,z,sz,cnt,tmp,res,a,b;
string s,t;

int main(){
//	cout<<fixed<<setprecision(0);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	x = 1, y = 2;
    cin>>n;
    rep(i,1,n){
    	rep(j,i,n/2)cout<<y<<' ', y+=2;
    	if(i>(n+1)/2)rep(j,n-i+1,n/2)cout<<y<<' ', y+=2;
    	if(i<=(n+1)/2)rep(j,1,i*2-1)cout<<x<<' ', x+=2;
    	else rep(j,1,(n-i)*2+1)cout<<x<<' ', x+=2;
    	rep(j,i,n/2)cout<<y<<' ', y+=2;
    	if(i>(n+1)/2)rep(j,n-i+1,n/2)cout<<y<<' ', y+=2;
    	cout<<endl;
	}
    return 0;
}