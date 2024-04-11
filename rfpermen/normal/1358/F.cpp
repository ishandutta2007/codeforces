#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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

ll n,x[MAX],y[MAX],hit,k,a,b,c,d;
string ans;

inline bool tes(){
	rep(i,1,n)if(y[i]<=y[i-1])return false;
	return true;
}

inline bool cek(){
	rep(i,1,n)if(x[i]!=y[i])return false;
	return true;
}
inline bool ceker(){
	rep(i,1,n)if(x[i]!=y[n-i+1])return false;
	return true;
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>y[i];
    
    if(n==1)return cout<<(x[1]==y[1] ? "SMALL\n0\n" : "IMPOSSIBLE\n"), 0;
    if(n==2){
    	a = min(x[1],x[2]), b = max(x[1],x[2]);
    	c = y[1], d = y[2];
    	while(1){
    		if(c>d)swap(c,d);
    		if(c<=a||d<b)break;
    		k = (d-a)/c;
    		if(!k)return cout<<"IMPOSSIBLE\n",0;
    		hit+=k, d-= k*c;
		}
		if(c<a||d<b)return cout<<"IMPOSSIBLE\n",0;
		k = (d-b)/c, hit+=k, d-= k*c;
		if(c!=a||d!=b)return cout<<"IMPOSSIBLE\n",0;
		
		if(hit>2e5)return cout<<"BIG\n"<<hit<<endl,0;
		
		c = y[1], d = y[2];
		while(1){
    		if(c>d)ans.pb('R'), swap(c,d);
    		if(c==a&&d==b)break;
    		ans.pb('P'), d-= c;
		}
		if(x[1]>x[2])ans.pb('R');
	}
	else {
		a = min(x[1],x[2]), b = max(x[1],x[2]);
		while(1){
			if(cek()||ceker())break;
			if(!tes())reverse(y+1,y+1+n), ans.pb('R');
			if(!tes())break;
			ans.pb('P');
			rap(i,n,1)y[i]-= y[i-1];
		}
		if(!(cek()||ceker()))return cout<<"IMPOSSIBLE\n",0;
		if(ceker())ans.pb('R');
		for(auto i:ans)if(i=='P')++hit;
		if(hit>2e5)return cout<<"BIG\n"<<hit<<endl,0;
	}
	
	reverse(all(ans));
	cout<<"SMALL\n"<<ans.size()<<endl<<ans<<endl;
    return 0;
}