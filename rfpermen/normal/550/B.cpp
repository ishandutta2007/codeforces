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
const int MOD=1000000000 + 9;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,l,r,k,x[20],ans;

void f(int id,int mn,int mx,int ttl){
	if(id>n||ttl>r)return;
	if(ttl+x[id]>=l&&ttl+x[id]<=r&&max(mx,x[id])-min(mn,x[id])>=k)ans++;
	f(id+1,min(mn,x[id]),max(mx,x[id]),ttl+x[id]);
	f(id+1,mn,mx,ttl);
	return;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>r>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)f(i+1,x[i],x[i],x[i]);
    cout<<ans<<endl;
    return 0;
}