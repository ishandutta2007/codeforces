#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a;
bool x[MAX];
string s;

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size(); s = 'a'+s;
    cin>>m;
    while(m--){
    	cin>>a;
    	x[a]^=1;
    	x[n-a+2]^=1;
	}
	rep(i,1,n)x[i]^=x[i-1];
	rep(i,1,n){
		if(!x[i])cout<<s[i];
		else cout<<s[n-i+1];
	}
    return 0;
}