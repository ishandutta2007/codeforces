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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

ll n,x,y,tgt,res,le,ri,mid,ans,a,b,c,d,ab,bc,cd,da;

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y>>tgt;
    le = 0, ri = 2*n;
    while(le<=ri){
    	mid = le+ri>>1;
    	res = 1 + mid*(mid+1)*2;
    	a = max(0ll,mid - x + 1);
		b = max(0ll,mid - y + 1);
		c = max(0ll,x + mid - n);
		d = max(0ll,y + mid - n);
    	res-= a*a + b*b + c*c + d*d;
    	ab = max(0ll,a+b-mid-1);
    	bc = max(0ll,c+b-mid-1);
    	cd = max(0ll,c+d-mid-1);
    	da = max(0ll,a+d-mid-1);
    	res+= ab*(ab+1)/2 + bc*(bc+1)/2 + cd*(cd+1)/2 + da*(da+1)/2;
//    	cout<<mid<<' '<<res<<endl;
    	if(res>=tgt)ans = mid, ri = mid-1;
    	else le = mid+1;
	}
	cout<<ans<<endl;
    return 0;
}