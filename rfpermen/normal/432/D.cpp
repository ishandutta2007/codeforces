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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000204921;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll n,hs[MAX],ha[MAX],ss[MAX],aa[MAX],key,le,ri,mid,res,ans[MAX];
string s;
vector<pii> hsl;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size(); s = 'a'+s;
    key = 36671;
    ss[0] = aa[0] = key;
    rep(i,1,n){
    	hs[i] = hs[i-1]*key + s[i];
		ha[i] = (ha[i-1]*key + s[i])%MOD;
		ss[i] = ss[i-1]*key, aa[i] = aa[i-1]*key%MOD;
	}
	rep(i,1,n){
		le = i, ri = n, res = 0;
		while(le<=ri){
			mid = le+ri>>1;
			if(	hs[mid] - hs[i-1]*ss[mid-i] == hs[mid-i+1] && 
				((ha[mid] - ha[i-1]*aa[mid-i])%MOD + MOD )%MOD == ha[mid-i+1])res = mid-i+1, le = mid+1;
			else ri = mid-1;
		}
		ans[res]++;
	}
	rap(i,n,1)ans[i]+=ans[i+1];
	rep(i,1,n){
		if(	hs[n] - hs[n-i]*ss[i-1] == hs[i] && 
			((ha[n] - ha[n-i]*aa[i-1])%MOD + MOD )%MOD == ha[i])hsl.pb({i,ans[i]});
	}
	cout<<hsl.size()<<endl;
	for(auto i:hsl)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}