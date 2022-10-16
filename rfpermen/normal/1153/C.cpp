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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,k,x,y,z,a,b,cnt,tmp,res,id,sz,ans,hit,c;
string s,t;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>s;
    sz = s.size()-1;
    if(s[0]=='?')s[0] = '(';
    if(s[sz]=='?')s[sz] = ')';
    if(sz%2==0||s[0]!='('||s[sz]!=')')return cout<<":(",0;
    sz--;
    rep(i,1,sz){
    	if(s[i]==')')b++;
    	else if(s[i]=='(')a++;
    	else c++;
	}
    rep(i,1,sz){
    	if(s[i]=='(')hit++, a--;
    	else if(s[i]==')'){
    		if(!hit)return cout<<":(",0;
    		hit--, b--;
		}
		else {
			c--;
			if(hit+a+1<=b+c)hit++, s[i] = '(';
			else if(hit)hit--, s[i] = ')';
			else return cout<<":(",0;
		}
//		db(s);
	}
	if(hit)cout<<":(";
	else cout<<s<<endl;
	return 0;
}