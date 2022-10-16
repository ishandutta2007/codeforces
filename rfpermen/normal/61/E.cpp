#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x[MAX],cnt,bt;
ll ans,le[MAX],ri[MAX],ret,let;
map<int,int> m;
set<int> s;

inline void updl(int i,int up){
	for(; i<=n; i+=(i&-i))le[i]+=up;
}
inline void updr(int i){
	for(; i<=n; i+=(i&-i))ri[i]++;
}

inline void quel(int i){
	let = 0;
	for(; i> 0; i-=(i&-i))let+=le[i];
}
inline void quer(int i){
	ret = 0;
	for(; i> 0; i-=(i&-i))ret+=ri[i];
}

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], s.insert(x[i]);
    for(auto i:s)m[i] = ++cnt;
    rep(i,1,n)x[i] = m[x[i]];
//    rep(i,1,n)cout<<x[i]<<" - "; cout<<endl;
    rep(i,2,n)updl(x[i],1);
    quel(4);
    rep(i,2,n){
    	updr(x[i-1]);
    	quer(x[i]);
    	quel(x[i]-1);
//    	cout<<x[i]<<endl;
    	ret = i-1-ret;
//    	cout<<ret<<" "<<let<<endl;
    	ans+=ret*let;
//    	quel(4);
//    	cout<<"LEt = "<<let<<endl;
    	updl(x[i],-1);
	}
	cout<<ans<<endl;
    return 0;
}