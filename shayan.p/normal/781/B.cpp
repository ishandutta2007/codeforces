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

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=1e9+7;

ll n;
ll ans[maxn];
string str[maxn][2];
vector<ll>v[2*maxn];
vector<ll>rev[2*maxn];
vector<ll>scc[2*maxn];

ll scc_num[2*maxn];
ll topol[2*maxn];
bool mark[2*maxn];
ll f[2*maxn];
ll t,scc_no;
// 2k is // 2k+1 !is

void build_edge(ll a,ll b){// if a then !b
	if(b%2){
		v[a].PB(b-1);
		rev[b-1].PB(a);
	}
	else{
		v[a].PB(b+1);
		rev[b+1].PB(a);
	}
}

void dfs1(ll u){
	mark[u]=1;
	REP(i,sz(v[u]))
		if(!mark[v[u][i]])
			dfs1(v[u][i]);
	f[t++]=u;
}

void dfs2(ll u){
	mark[u]=1;
	scc_num[u]=scc_no;
	REP(i,sz(rev[u]))
		if(!mark[rev[u][i]])
			dfs2(rev[u][i]);
}

void topol_sort(ll u){
	mark[u]=1;
	REP(i,sz(scc[u]))
		if(!mark[scc[u][i]])
			topol_sort(scc[u][i]);
	topol[u]=t++;
}

void SCC_GRAPH(){
	REP(i,2*n){
		REP(j,sz(v[i])){
			ll y=v[i][j];
			if(scc_num[i]!=scc_num[y]){
				scc[scc_num[i]].PB(scc_num[y]);
			}
		}
	}
}

void SCC(){
	REP(i,2*n)
		if(!mark[i])
			dfs1(i);
	memset(mark,0,sizeof mark);
	REPD(i,2*n){
		if(!mark[f[i]]){
			dfs2(f[i]);
			scc_no++;
		}
	}
}

void solve_2sat(){
	SCC();
	SCC_GRAPH();
	memset(mark,0,sizeof mark);
	t=0;
	REP(i,scc_no)
		if(!mark[i])
			topol_sort(i);
	REP(i,n){
		if(scc_num[2*i]==scc_num[2*i+1]){
			cout<<"NO";
			exit(0);
		}
		if(topol[scc_num[2*i]]>topol[scc_num[2*i+1]])// 2*i ghabl oomade
			ans[i]=1;
		else
			ans[i]=0;
	}
}

int main(){
	cin>>n;
	REP(i,n){
		string s1,s2;cin>>s1>>s2;
		str[i][0]=s1.substr(0,3);
		str[i][1]=s1.substr(0,2)+s2.substr(0,1);
	}
	REP(i,n){
		REP(j,n){
			if(i==j)continue;
			if(str[i][0]==str[j][0])build_edge(2*i,2*j);
			if(str[i][0]==str[j][1])build_edge(2*i,2*j+1);
			if(str[i][1]==str[j][0])build_edge(2*i+1,2*j);
			if(str[i][1]==str[j][1])build_edge(2*i+1,2*j+1);
			if(str[i][0]==str[j][0])build_edge(2*i+1,2*j);
		}
	}
	solve_2sat();
	cout<<"YES\n";
	REP(i,n)
		cout<<str[i][(ans[i]?1:0)]<<endl;
}