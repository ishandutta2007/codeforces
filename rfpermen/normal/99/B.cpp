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

int n;
pii x[MAX];
bool st;
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    if(x[1].fi==x[n].fi)return cout<<"Exemplary pages.",0;
    if(n==2){
    	if((x[1].fi+x[2].fi)&1)return cout<<"Unrecoverable configuration.",0;
    	x[3].fi = (x[1].fi+x[2].fi)/2;
    	cout<<x[3].fi-x[1].fi<<" ml. from cup #"<<x[1].se<<" to cup #"<<x[n].se<<".";
    	return 0;
	}
    st = 1;
    rep(i,3,n-1)if(x[i].fi!=x[i-1].fi)st = 0;
    if(!st)return cout<<"Unrecoverable configuration.",0;
    if(x[1].fi+x[n].fi!=2*x[2].fi)return cout<<"Unrecoverable configuration.",0;
    cout<<x[2].fi-x[1].fi<<" ml. from cup #"<<x[1].se<<" to cup #"<<x[n].se<<".";
    return 0;
}