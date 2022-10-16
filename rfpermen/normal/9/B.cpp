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

int n,ans;
double a,b,x[1005],mn,mn2,p1,p2,py;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    rep(i,1,n)cin>>x[i];
    cin>>p1>>p2;
    mn = 1e9;
    rep(i,2,n){
    	py = x[i]/a + sqrt((p1-x[i])*(p1-x[i]) + p2*p2)/b;
    	//cout<<py<<" "<<sqrt((p1-x[i])*(p1-x[i]) + p2*p2)<<endl;
    	if(py<mn)mn = py, mn2  = (p1-x[i])*(p1-x[i])+p2*p2, ans = i;
    	else if(py==mn && mn2>(p1-x[i])*(p1-x[i])+p2*p2)mn = (p1-x[i])*(p1-x[i])+p2*p2, ans = i;
	}
	cout<<ans<<endl;
    return 0;
}