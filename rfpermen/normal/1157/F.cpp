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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,x[MAX],y,nw,ans,pos,cnt;
deque<int> dq;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>y, x[y]++;
    rep(i,1,200001){
    	if(x[i]<2){
    		if(x[i]==1)++nw;
    		if(nw==1&&x[i-1])++nw;
    		if(ans<nw){
    			ans = nw;
    			pos = i-(1-x[i]);
			}
    		nw = 0;
		}
		else if(!nw)nw = x[i-1]+x[i];
		else nw+= x[i];
	}
	cout<<ans<<endl;
	if(x[pos]==1)--cnt;
	rap(i,pos,1){
		if(!x[i])break;
		if(x[i]==1)++cnt;
		x[i]--, dq.pf(i);
		rep(j,1,x[i])dq.pb(i);
		if(cnt)break;
	}
	--ans;
	rep(i,0,ans)cout<<dq[i]<<' '; cout<<endl;
    return 0;
}