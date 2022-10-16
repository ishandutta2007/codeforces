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
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
ll n,x[MAX],y[MAX],ax,ay,bx,by,a,b,t,rem,tmp,nw,ans;
 
int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>a>>b>>t;
    while(x[n]*ax<=2e16&&y[n]*ay<=2e16)++n, x[n] = ax*x[n-1]+bx, y[n] = ay*y[n-1]+by;
    rep(i,0,n){
    	tmp = t - abs(x[i]-a) - abs(y[i]-b);
    	if(tmp<0)continue;
    	nw = 1, rem = tmp;
    	rep(j,i+1,n){
    		rem-= abs(x[j]-x[j-1]) + abs(y[j]-y[j-1]);
    		if(rem<0)break;
    		++nw;
		}
		ans = max(ans,nw);
    	nw = 1, rem = tmp;
    	rap(j,i-1,0){
    		rem-= abs(x[j]-x[j+1]) + abs(y[j]-y[j+1]);
    		if(rem<0)break;
    		++nw;
		}
		ans = max(ans,nw);
	}
	cout<<ans<<endl;
    return 0;
}