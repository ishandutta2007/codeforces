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
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;

ll n,m,cl[MAX],a,b,ans;
vector<int> v[MAX];
bool st;

bool f(int nw){
	if(cl[nw]==1)++a;
	else ++b;
	for(int i:v[nw]){
		if(cl[i]){
			if(cl[i]==cl[nw])return true;
		}
		else {
			cl[i] = -cl[nw];
			if(f(i))return true;
		}
	}
	return false;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(m==0)return cout<<"3 "<<n*(n-1)*(n-2)/6<<endl,0;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	rep(i,1,n)if(!cl[i]){
		a = b = 0;
		cl[i] = 1;
		if(f(i))return cout<<"0 1\n",0;
//		cout<<a<<' '<<b<<endl;
		if(a+b>2){
			if(!st)st = 1, ans = 0;
			ans+= a*(a-1)/2 + b*(b-1)/2;
		}
		else if(a+b==2 && !st)ans+= n-2;
	}
	cout<<(st ? "1 " : "2 ")<<ans<<endl;
	return 0;
}