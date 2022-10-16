#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 420691273;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,a,b,t,x[MAX],y[MAX],ans,z[MAX],tmp,nw,le,ri,mid,res;
char c;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>t;
    rep(i,1,n){
    	cin>>c;
    	z[i] = (c=='w')*b;
	}
	t-= z[1]+1;
	if(t<0)return cout<<"0\n",0;
	ans = 1;
	rep(i,2,n){
		x[i] = x[i-1] + z[i] + a + 1;
		if(t>=x[i])ans = max(ans,(ll)i);
	}
	rap(i,n,2){
		y[i] = y[i+1] + z[i] + a + 1;
		if(t>=y[i])ans = max(ans,n-i+2);
	}
	if(ans==n)return cout<<ans<<endl,0;
	rep(i,2,n){
		tmp = t-x[i]-(i-1)*a;
		if(tmp>0){
			le = i+1, ri = n, res = 0;
			while(le<=ri){
				mid = le+ri>>1;
				if(tmp<y[mid])le = mid+1;
				else res = n-mid+1, ri = mid-1;
			}
			ans = max(ans,i+res);
		}
		
		tmp = t-y[n-i+2]-(i-1)*a;
		if(tmp>0){
			le = 2, ri = n-i+1, res = 0;
			while(le<=ri){
				mid = le+ri>>1;
				if(tmp<x[mid])ri = mid-1;
				else res = mid-1, le = mid+1;
			}
			ans = max(ans,i+res);
		}
	}
	cout<<ans<<endl;
    return 0;
}