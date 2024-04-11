#include <bits/stdc++.h>

#pragma GCC optimize("Os")
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

//int n,ans[MAX],y;
pii x[10];
set<pii> s;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,8)cin>>x[i].fi>>x[i].se, s.insert(x[i]);
    sort(x+1,x+1+8);
    if(s.size()!=8)return cout<<"ugly",0;
    rep(i,2,3)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    rep(i,5,5)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    rep(i,7,8)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    if(x[3].fi==x[4].fi||x[5].fi==x[6].fi)return cout<<"ugly",0;
    rep(i,1,8)swap(x[i].fi,x[i].se);
    sort(x+1,x+1+8);
    rep(i,2,3)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    rep(i,5,5)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    rep(i,7,8)if(x[i-1].fi!=x[i].fi)return cout<<"ugly",0;
    if(x[3].fi==x[4].fi||x[5].fi==x[6].fi)return cout<<"ugly",0;
    cout<<"respectable";
    return 0;
}