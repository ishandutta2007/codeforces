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
const int MAX = 15+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,k,x,le,len;
priority_queue<pii> mx;
priority_queue<pii, vector<pii>, greater<pii>> mn;
vector<int> ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x;
    	mn.push({x,i}), mx.push({x,i});
    	if(mx.top().fi-mn.top().fi>k){
    		if(x==mx.top().fi){
    			while(mx.top().fi-mn.top().fi>k)le = max(mn.top().se,le), mn.pop();
			}
			else {
				while(mx.top().fi-mn.top().fi>k)le = max(mx.top().se,le), mx.pop();
			}
		}
		if(i-le==len)ans.pb(i);
		else if(i-le>len)ans.clear(), len = i-le, ans.pb(i);
	}
	cout<<len<<' '<<ans.size()<<endl;
	for(auto i:ans)cout<<i-len+1<<' '<<i<<endl;
    return 0;
}