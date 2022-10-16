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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
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
const int block = 316;

int tc,sz,cur,dp[MAX],id,nw;
ll x;
bool ty[MAX];
string s;
vector<ll> ans;

int f(){
	bool &st = ty[nw];
	int &ret = dp[nw]; ret = -1;
	++nw;
	while(1){
		if(s[nw]=='('){
			if(ret==-1)ret = f();
			else if(st)ret+= f();
			else ret = min(ret,f());
		}
		else if(s[nw]=='*'){
			if(ret==-1||!st)ret = 1;
			else ++ret;
		}
		else if(s[nw]=='P')st = 1;
		else if(s[nw]=='S')st = 0;
		else if(s[nw]==')')break;
		++nw;
	}
	return ret;
}

void bt(bool z){
	bool st = ty[nw];
	int ret = dp[nw];
	++nw;
	while(1){
		if(s[nw]=='('){
			if(dp[nw]==ret||st){
				bt(z);
				if(!st)z = 0;
			}
			else bt(0);
		}
		else if(s[nw]=='*'){
			ans.pb(x*z);
			if(!st)z = 0;
		}
		else if(s[nw]==')')break;
		++nw;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>x;
    	getline(cin,s);
    	sz = s.size();
    	s = '(' + s, s.pb(')');
    	nw = 0, x*= f(), id = 0, ans.clear();
    	nw = 0, bt(1);
    	cout<<"REVOLTING";
    	for(auto i:ans)cout<<' '<<i;
    	cout<<endl;
	}
    return 0;
}