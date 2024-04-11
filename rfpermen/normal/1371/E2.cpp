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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,p,x[MAX],le,ri,mid,res,nw,mx;

int main(){
// cout<<fixed<<setprecision(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    le = 1, ri = MOD;
    while(le<=ri){
    	mid = le+ri>>1;
    	nw = mid-1;
    	rep(i,1,n)if(x[i]>nw+i){
    		nw = -1;
    		break;
		}
		if(nw!=-1)res = mid, ri = mid-1;
		else le = mid+1;
	}
	rap(i,n,p)mx = max(mx,i-max(0,x[i]-res));//, cout<<i-max(0,x[i]-res)<<' '; cout<<endl;
	cout<<max(0,p-mx)<<endl;
//	db(mx);
	rep(i,1,max(0,p-mx))cout<<res+i-1<<' '; cout<<endl;
    return 0;
}