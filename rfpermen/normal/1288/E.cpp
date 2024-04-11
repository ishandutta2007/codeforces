#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 6e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,m,k,x,le[MAX],ls[MAX],ans[MAX],bit[MAX];

inline void upd(int i,bool val){
	if(val)for(;i<=m;i+=(i&-i))bit[i]++;
	else for(;i<=m;i+=(i&-i))bit[i]--;
}

int ret;
inline int que(int i){
	ret = 0;
	for(;i>0;i-=(i&-i))ret+=bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    m = n+k;
    rep(i,1,n)upd(i,1), ls[n-i+1] = le[i] = i;
    rep(i,n+1,m){
    	cin>>x;
    	ans[x] = max(ans[x],n-que(ls[x]));
    	upd(ls[x],0);
		ls[x] = i, le[x] = 1;
		upd(i,1);
	}
	rep(i,1,n)cout<<le[i]<<' '<<max(ans[i],n-que(ls[i]))+1<<endl;
    return 0;
}