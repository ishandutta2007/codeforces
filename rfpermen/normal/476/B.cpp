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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int a,b,x;
string s;
double fact[11],dv;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    rep(i,1,10)fact[i] = i*fact[i-1];
    cin>>s;
    for(auto i:s)if(i=='+')x++; else if(i=='-')x--;
    cin>>s;
    for(auto i:s)if(i=='+')a++; else if(i=='-')a--; else b++;
    dv = pow(2,b);
    a = abs(a-x);
    rep(i,0,b){
    	if(b-2*i==a){
    		cout<<fact[b]/fact[i]/fact[b-i]/dv;
    		return 0;
		}
	}
	cout<<0;
    return 0;
}