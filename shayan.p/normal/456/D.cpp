// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll MAX_NODE=1e5+10;
const ll MAX_ASCII=28;
// 1 indexed
ll trie[MAX_NODE][MAX_ASCII];
ll t;//last used
pair<bool,bool> node[MAX_NODE];

void add(string &s){
	ll now=0;
	REP(i,sz(s)){
		if(trie[now][s[i]-'a']==0)
			trie[now][s[i]-'a']=++t;
		now=trie[now][s[i]-'a'];
	}
}

pair<bool,bool> dfs(ll u){//can win// can loose
	bool any_child=0;
	REP(i,MAX_ASCII){
		if(trie[u][i]!=0){
			any_child=1;
			pair<bool,bool>p=dfs(trie[u][i]);
			node[u].F|=(!p.F);
			node[u].S|=(!p.S);
		}
	}
	if(!any_child){
		node[u].F=0;
		node[u].S=1;
	}
	return node[u];
}

int main(){
	ll n,k;cin>>n>>k;
	REP(i,n){
		string s;cin>>s;
		add(s);
	}
	pair<bool,bool> state=dfs(0);//root
	//can win // can loose
	
	// base on the table we made->
	if(!state.F)
		cout<<"Second";
	else if(!state.S&&!(k%2))
		cout<<"Second";
	else
		cout<<"First";
}