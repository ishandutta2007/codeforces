#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const ll aa = 97;
const ll bb = 31;

ll a,b,id,sz,hs,ans,x,y;
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    hs = 1;
    rep(i,1,sz){
    	while(a==b&&i+x<=sz){
    		if(x)hs*=aa;
    		a = a*aa+s[x]-'_';
    		b = b*aa+s[i+x]-'_';
    		++x;
		}
    	if(i+x>=sz)break;
		b-= hs*(s[i]-'_');
		b = b*aa+s[i+x]-'_';
	}
	x--;
	a = b = 0;
	hs = 1;
	for(int i = 0; i<sz; i++){
    	a = a*aa+s[i]-'_';
    	b = b+hs*(s[sz-i]-'_');
    	if(a==b&&x>i)y = i+1;
    	hs*=aa;
	}
	if(!y)cout<<"Just a legend";
	else {
		x = y-1;
		rep(i,0,x)cout<<s[i];
	}
	return 0;
}