#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,k,x[MAX],y[MAX],z[MAX],jmp[MAX],mx,ans[MAX],cl,ls;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i], y[x[i]] = i;
    rep(i,1,n)cin>>z[i], z[i] = y[z[i]];
    rep(i,1,n){
    	mx = max(mx,z[i]);
    	jmp[z[i]] = mx;
	}
	ls = 1;
	rep(i,1,n){
		if(!ans[i])ans[i] = ++cl;
		rep(j,ls,jmp[i])ans[j] = ans[i];
		ls = jmp[i]+1;
	}
	if(ans[n]<k)cout<<"NO\n";
	else {
		cout<<"YES\n";
		rep(i,1,n){
			if(ans[y[i]]>26)cout<<'z';
			else cout<<(char)(ans[y[i]]+'a'-1);
		}
		cout<<endl;
	}
	return 0;
}