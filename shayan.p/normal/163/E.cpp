// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5, MAX=1e6+10;

int where[maxn], C;
int nxt[MAX][26], f[MAX];

void buildAho(){
    queue<int> q;
    for(int i=0;i<26;i++){
	if(nxt[0][i]!=0) q.push(nxt[0][i]);
    }
    while(sz(q)){
	int u=q.front();
	q.pop();
	for(int i=0;i<26;i++){
	    if(nxt[u][i]==0)
		nxt[u][i]= nxt[ f[u] ][i];
	    else
		f[ nxt[u][i] ]= nxt[ f[u] ][i], q.push(nxt[u][i]);
	}
    }
}

vector<int> v[MAX];
pii seg[MAX];
int CC;

void dfs(int u){
    seg[u].F=CC++;
    for(int y:v[u])
	dfs(y);
    seg[u].S=CC;
}
void buildG(){
    for(int i=1;i<=C;i++)
	v[f[i]].PB(i);
    dfs(0);
}

int fn[MAX];

void add(int pos,int x){
    for(pos+=3; pos<MAX; pos+= pos & -pos)
	fn[pos]+=x;
}
int ask(int pos){
    int ans=0;
    for(pos+=3; pos>0; pos-= pos & -pos)
	ans+= fn[pos];
    return ans;
}

bool in[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q,n; cin>>q>>n;

    for(int i=0;i<n;i++){
	string s; cin>>s;

	int tmp=0;
	for(char ch:s){
	    if(nxt[tmp][ch-'a'] == 0)
		nxt[tmp][ch-'a']=++C;
	    tmp= nxt[tmp][ch-'a'];
	}
	where[i]=tmp;
    }
    buildAho();
    buildG();

    auto ins=[](int i,int x){
	add(seg[where[i]].F, x);
	add(seg[where[i]].S,-x);
    };
    auto toInt=[](string s){
	stringstream ss;
	ss<<s;
	int ans; ss>>ans;
	return ans;
    };
    
    for(int i=0;i<n;i++){
	ins(i,1), in[i]=1;
    }
    
    while(q--){
	string s; cin>>s;
	char ch=s[0];
	s=s.substr(1);
	if(ch == '+'){
	    int id=toInt(s)-1;
	    if(in[id]==0)  ins(id,1);
	    in[id]=1;
	}
	if(ch == '-'){
	    int id=toInt(s)-1;
	    if(in[id]==1)  ins(id,-1);
	    in[id]=0;
	}
	if(ch == '?'){
	    int tmp=0;
	    ll ans=0;
	    for(char ch:s){
		tmp= nxt[tmp][ch-'a'];
		ans+= ask(seg[tmp].F);
	    }
	    cout<<ans<<"\n";
	}	
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")