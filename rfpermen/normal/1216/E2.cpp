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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
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
const int MAX = 3e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,k,le,ri,mid,hit,res,ans,ub[11],lb[11];

inline ll comp(ll x){
	ll ret = 0, tmp;
	rep(i,1,9){
		if(x<lb[i])break;
		if(x<ub[i]){
			tmp = x-lb[i]+1;
			ret+=tmp*(tmp+1)*i/2;
			break;
		}
		tmp = lb[i+1] - lb[i];
		ret+=tmp*(tmp+1)*i/2;
		ret+=tmp*(x-ub[i])*i;
	}
	return ret;
}

inline int f(ll x,ll y){
	string s = "";
	while(x)s.pb(x%10), x/=10;
	reverse(all(s));
	return s[y-1];
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    lb[1] = 1, ub[1] = 9;
    rep(i,2,10)lb[i] = lb[i-1]*10, ub[i] = ub[i-1]*10 + 9;
    ll tmp = 0, re = 0, mul = 1;
//    rep(i,1,101024709){
//    	if(i==lb[mul+1])++mul;
//    	tmp+=mul;
//    	re+=tmp;
//	}
//	db(re);
    cin>>tc;
    while(tc--){
    	cin>>k;
    	le = 1, ri = 500000000;
    	while(le<=ri){
    		mid = le+ri>>1;
    		if(k<=comp(mid))res = mid, ri = mid-1;
    		else le = mid+1;
		}
		k-=comp(res-1);
//		db(k);
		rep(i,1,10){
			tmp = lb[i+1] - lb[i];
			if(k>tmp*i)k-=tmp*i;
			else {
				res = lb[i] + (k-1)/i;
				k%=i;
				if(k==0)k+=i;
				break;
			}
		}
		cout<<f(res,k)<<endl;
	}
    return 0;
}