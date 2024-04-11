#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll n,x[MAX],sm,tmp,ans,a,b,md,hit,as,vr,z;
 
inline void solve(ll i){
	as = (i+1)/2;
	a = b = tmp = hit = 0;
	rep(j,1,n){
		if(x[j]){
			vr = x[j];
			if(hit<as-1){
				z = min(vr,as-hit-1);
				a+= j*z;
				vr-= z;
				hit+= z;
			}
			if(hit==as-1){
				if(vr){
					md = j;
					--vr;
					++hit;
				}
			}
			if(vr){
				z = min(vr,i-hit);
				b+= j*z;
				vr-= z;
				hit+= z;
			}
			if(hit==i){
				tmp+= md*(as-1) - a + b - md*(i-as);
				a = b = hit = 0;
			}
			vr%=i;
			if(hit<as-1){
				z = min(vr,as-hit-1);
				a+= j*z;
				vr-= z;
				hit+= z;
			}
			if(hit==as-1){
				if(vr){
					md = j;
					--vr;
					++hit;
				}
			}
			if(vr){
				z = min(vr,i-hit);
				b+= j*z;
				vr-= z;
				hit+= z;
			}
		}
	}
	ans = min(ans,tmp);
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], sm+= x[i];
    ans = 2e18;
    for(ll i = 2; i*i<=sm; ++i){
    	if(sm%i)continue;
    	while(sm%i==0)sm/=i;
    	solve(i);
	}
	if(sm!=1)solve(sm);
	if(ans>1e18)cout<<"-1\n";
	else cout<<ans<<endl;
    return 0;
}