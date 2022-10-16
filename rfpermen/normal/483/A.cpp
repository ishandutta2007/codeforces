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

ll n,m,k,a,b,c,x[105],y[105],z,sz,T,len;
string s,t;
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    if(b-a<=1)cout<<-1;
    else if(b-a==2){
    	if(__gcd(a,b)!=1 && __gcd(a,a+1)==1 && __gcd(b-1,b)==1)cout<<a<<" "<<a+1<<" "<<b;
    	else cout<<-1;
	}
	else if(a&1)cout<<a+1<<" "<<a+2<<" "<<a+3;
	else cout<<a<<" "<<a+1<<" "<<a+2;
    return 0;
}