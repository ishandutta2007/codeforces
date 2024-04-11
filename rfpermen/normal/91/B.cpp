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
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,bit[MAX],ret,ans[MAX];
pii x[MAX];

inline void upd(int i,int y){
	for(; i<=n; i+=(i&-i))bit[i] = min(bit[i],y);
	return;
}
inline int que(int i){
	ret = i;
	for(; i; i-=(i&-i))ret = min(ret,bit[i]);
	return ret;
}
int main(){
//	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rap(i,n,1)cin>>x[i].fi, x[i].se = -i;
    sort(x+1,x+1+n);
    rep(i,1,n)bit[i] = n;
    rep(i,1,n){
    	x[i].se*=-1;
    	ans[x[i].se] = x[i].se - que(x[i].se);
    	upd(x[i].se,x[i].se);
	}
	rap(i,n,1)cout<<ans[i]-1<<" ";
	return 0;
}