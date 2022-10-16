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
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,a,b,c,x,y,z,sz,cnt,ans,tmp;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y>>a>>b;
    if((n<=a || m<=b )&& !((x==1 && y==1)||(x==1 && y==m)||(x==n && y==1)||(x==n && y==m)))return cout<<"Poor Inna and pony!",0;
    ans = 1e9;
    if((x-1)%a==0 && (y-1)%b==0 && abs((x-1)/a - (y-1)/b)%2==0)ans = min(ans,max((x-1)/a , (y-1)/b));
    if((x-1)%a==0 && (m-y)%b==0 && abs((x-1)/a - (m-y)/b)%2==0)ans = min(ans,max((x-1)/a , (m-y)/b));
    if((n-x)%a==0 && (y-1)%b==0 && abs((n-x)/a - (y-1)/b)%2==0)ans = min(ans,max((n-x)/a , (y-1)/b));
    if((n-x)%a==0 && (m-y)%b==0 && abs((n-x)/a - (m-y)/b)%2==0)ans = min(ans,max((n-x)/a , (m-y)/b));
    if(ans==1e9)cout<<"Poor Inna and pony!";
    else cout<<ans;
    return 0;
}