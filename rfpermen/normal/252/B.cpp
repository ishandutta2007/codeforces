#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define pii pair<int,int> 
#define pdd pair<double,double> 
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

int n,x[MAX],y,id;
map<int,int> m;
bool st,ss;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], m[x[i]]++;
    if(n<3||(n==3&&x[1]==x[3]))return cout<<-1,0;
    st=1,y=x[1];
    rep(i,2,n)if(y!=x[i])st=0;
    if(st)return cout<<-1,0;
    for(auto i:m)if(i.se!=n-1)y=i.fi;
    rep(i,1,n)if(y==x[i])id=i;
    rep(i,1,n){
    	if(x[id]==x[i])continue;
    	swap(x[id],x[i]);
    	st=ss=1;
    	rep(i,2,n)if(x[i]>x[i-1])st=0;
    	rep(i,2,n)if(x[i]<x[i-1])ss=0;
    	if(!(ss|st))return cout<<id<<" "<<i,0;
    	swap(x[id],x[i]);
	}
    return 0;
}