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

ll n,k,a,b,c,x[123],y,z,sz,T,pv;
string s,t;
bool st;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    rep(i,0,sz)if(s[i]=='^')pv = i;
    rep(i,0,sz){
    	if(i==pv || s[i]=='=')continue;
    	if(i<pv)a+=(s[i]-'0')*(pv-i);
    	else b+=(s[i]-'0')*(i-pv);
	}
	if(a==b)cout<<"balance";
	else if(a>b)cout<<"left";
	else cout<<"right";
    return 0;
}