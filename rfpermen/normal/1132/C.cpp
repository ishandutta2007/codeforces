#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e3+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,k,x[MAX],y[MAX],z[MAX],a[MAX],b[MAX],mx,ans,cnt,c[4];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,k)cin>>a[i]>>b[i], x[a[i]]++, x[b[i]+1]--;
    rep(i,1,n){
    	x[i]+=x[i-1];
    	y[i]+=y[i-1];
    	z[i]+=z[i-1];
    	if(x[i]==1)y[i]++;
    	else if(x[i]==2)z[i]++;
    	if(x[i])mx++;
	}
	rep(i,1,k)rep(j,i+1,k){
		if(b[i]<a[j]||b[j]<a[i])cnt = y[b[i]] - y[a[i]-1] + y[b[j]] - y[a[j]-1];
		else {
			c[0] = a[i], c[1] = b[i], c[2] = a[j], c[3] = b[j];
			sort(c,c+4);
			cnt = y[c[1]-1] - y[c[0]-1] + z[c[2]] - z[c[1]-1] + y[c[3]] - y[c[2]];
		}
		ans = max(ans,mx-cnt);
	}
	cout<<ans<<endl;
	return 0;
}