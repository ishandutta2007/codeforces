#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e6+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,k,x,nw,sz,p[MAX],mx;
string s;
char y[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,2000001)p[i] = i;
    cin>>n;
    while(n--){
    	cin>>s>>k;
    	sz = s.size()-1;
    	while(k--){
    		cin>>x;
    		nw = x;
    		while(nw<=x+sz){
    			y[nw] = s[nw-x];
    			nw = p[nw] = par(nw+1);
			}
			mx = max(mx,x+sz);
		}
	}
	rep(i,1,mx)if(y[i])cout<<(char)y[i]; else cout<<'a';
	return 0;
}