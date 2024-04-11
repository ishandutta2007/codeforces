#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,p[MAX],sz[MAX],a,b,vis[MAX];
string s;
stack<pii> st;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void join(int x,int y){
	p[x] = y;
	sz[y]+=sz[x];
	sz[x] = 0;
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size();
    s = 'a'+s;
    rep(i,1,n){
    	p[i] = i;
    	if(s[i]=='[')sz[i] = 1, st.push({1,i});
    	else if(s[i]=='(')st.push({0,i});
    	else if(s[i]==']'){
    		if(!st.empty()&&st.top().fi==1){
    			if(vis[st.top().se-1]){
	    			a = par(st.top().se-1), b = par(st.top().se);
	    			if(a!=b)join(a,b);
				}
    			a = par(st.top().se), b = par(st.top().se+1);
    			vis[st.top().se] = 1, vis[i] = 1;
    			if(a!=b)join(a,b);
				st.pop();
				a = par(i-1), b = par(i);
				if(a!=b)join(a,b);
			}
			else while(!st.empty())st.pop();
		}
		else {
    		if(!st.empty()&&st.top().fi==0){
    			if(vis[st.top().se-1]){
	    			a = par(st.top().se-1), b = par(st.top().se);
	    			if(a!=b)join(a,b);
				}
    			a = par(st.top().se), b = par(st.top().se+1);
    			vis[st.top().se] = 1, vis[i] = 1;
    			if(a!=b)join(a,b);
				st.pop();
				a = par(i-1), b = par(i);
				if(a!=b)join(a,b);
			}
			else while(!st.empty())st.pop();
		}
	}
	a = 0;
	rep(i,1,n){
		if(sz[par(i)]>a&&par(i)!=i){
			a = sz[p[i]];
			b = i;
		}
	}
	cout<<a<<endl;
	if(a){
		a = b;
		b = par(a);
		rep(i,a,b)cout<<s[i];
		cout<<endl;
	}
	return 0;
}