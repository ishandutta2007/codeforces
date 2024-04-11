#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll tc,n,m,k,x[MAX],y,z,a,b,sz,tmp,res,id,neg;
string s,t;
bool st[MAX];
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s;
    	neg = 0;
    	for(auto j:s){
    		if(j=='.')break;
    		if(j=='-')neg = 1;
    		else x[i] = x[i]*10 + j-'0';
		}
		if(neg)x[i]*=-1;
    	reverse(all(s));
    	rep(j,0,4)if(s[j]!='0')st[i] = 1;
    	if(neg&&st[i])x[i]--;
    	z+=x[i];
	}
//	cout<<z<<endl;
	rep(i,1,n){
		if(z<0&&st[i])++z, cout<<x[i]+1<<endl;
		else cout<<x[i]<<endl;
	}
	return 0;
}