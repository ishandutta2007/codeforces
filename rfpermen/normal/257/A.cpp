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
//#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,k,a,b,c,x[100],y,z,sz,cnt,tmp,ans,le,ri;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    reverse(x+1,x+1+n);
    if(k>=m)return cout<<0,0;
    n = min(n,k);
	rep(i,1,n){
		k+=x[i]-1;
		if(k>=m)if(k>=m)return cout<<i,0;
		//cout<<k<<endl;
		n = max(n,min((ll)50,k));
	} 
	cout<<-1;
    return 0;
}