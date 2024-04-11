#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int x,y,n;
double rad[MAX],ans;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)return cout<<0,0;
    rep(i,1,n){
    	cin>>x>>y;
    	rad[i] = atan2(y,x);
    	if(rad[i]<0)rad[i]+=2*pi;
    	rad[i]/=pi/180.0;
    	if(rad[i]<=1e-9)rad[i] = 360.0;
	}
	sort(rad+1,rad+1+n);
	if(n==2)return cout<<min(rad[n]-rad[1],360.0-rad[n]+rad[1]),0;
	ans = rad[n]-rad[1];
	rep(i,2,n)ans = min(ans,360.0 - rad[i] + rad[i-1]);
	cout<<ans;
    return 0;
}