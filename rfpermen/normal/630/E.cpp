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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll a,b,x,y,ans,c,d;

int main(){
	cout<<fixed<<setprecision(12);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>x>>y;
    a+=1e9, b+=1e9, x+=1e9, y+=1e9;
    if(a&1){
    	if(b&1)c=1;
    	c+=(y-b)/2;
    	if(!(b&1))d=1;
    	d+=(y-b)/2;
	}
	else {
    	if(!(b&1))c=1;
    	c+=(y-b)/2;
    	if((b&1))d=1;
    	d+=(y-b)/2;
	}
//	cout<<c<<" "<<d<<endl;
	x-=a-1;
	cout<<max(c*((x+1)/2)+d*(x/2),d*((x+1)/2)+c*(x/2));
    return 0;
}