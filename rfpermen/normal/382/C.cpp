#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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

int n,x[MAX],y;
bool st = 1;
set<int> s;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)return cout<<-1,0;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    y = x[2]-x[1];
    if(n>2)y = min(y,x[3]-x[2]);
    rep(i,2,n){
    	if(x[i]-x[i-1]!=y)st = 0;
	}
	if(st){
		s.insert(x[1]-y);
		s.insert(x[n]+y);
	}
	else {
		st = 1;
		rep(i,2,n){
			if((x[i]-x[i-1])!=y){
				if(!st || (x[i]-x[i-1])!=y*2)return cout<<0,0;
				st = 0;
				s.insert(x[i-1]+y);
			}
		}
	}
	if(n==2){
		if(y%2==0)s.insert(x[1]+y/2);
	}
	cout<<s.size()<<endl;
	for(auto i:s)cout<<i<<" ";
    return 0;
}