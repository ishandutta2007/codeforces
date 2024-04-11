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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],le,ri,ls,a,b,tmp;
string ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    le = 1, ri = n;
    while(le<=ri){
    	if(x[le]<=ls&&x[ri]<=ls)break;
    	if(x[le]==x[ri]){
    		tmp = ls;
    		rep(i,le,ri){
    			if(ls>=x[i])break;
    			ls = x[i], ++a;
			}
			ls = tmp;
			rap(i,ri,le){
    			if(ls>=x[i])break;
    			ls = x[i], ++b;
			}
			if(a>b)while(a--)ans.pb('L');
			else while(b--)ans.pb('R');
			break;
		}
		else if(x[le]>ls&&(x[le]<x[ri]||x[ri]<=ls)){
			ls = x[le];
			++le;
			ans.pb('L');
		}
		else ls = x[ri], --ri, ans.pb('R');
	}
	cout<<ans.size()<<endl<<ans<<endl;
    return 0;
}