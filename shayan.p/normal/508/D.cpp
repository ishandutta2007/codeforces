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
const ll maxn=2e5+10;
const ll alpha=66;

#pragma GCC Optimize("Ofast")

vector<pll> v[alpha][alpha];
ll Out[alpha][alpha],In[alpha][alpha];
bool mark[alpha][alpha];
bool marke[maxn];
vector<pll>path;
pll start,finish;
ll vis=0;

inline void NO(){
	cout<<"NO";
	exit(0);
}

ll to(char ch){
	if('a'<=ch&&ch<='z')
		return ch-'a';
	if('A'<=ch&&ch<='Z')
		return 26+ch-'A';
	return 52+ch-'0';
}
char from(ll num){
	if(0<=num&&num<=25)
		return num+'a';
	if(26<=num&&num<=51)
		return num-26+'A';
	return num-52+'0';
}


void dfs(ll a,ll b){
	mark[a][b]=1;
	REP(i,sz(v[a][b])){
		ll A=v[a][b][i].F,B=v[a][b][i].S;
		vis++;
		if(!mark[A][B])
			dfs(A,B);
	}
}

void go_on(ll a,ll b,vector<pll>&put_path){
	put_path.PB(MP(a,b));
	if(sz(v[a][b])==0)return;
	pll P=v[a][b].back();
	v[a][b].POB();
	go_on(P.F,P.S,put_path);
}

void build_path(ll a,ll b){
	vector<pll>put_path;
	put_path.clear();
	go_on(a,b,put_path);
	if(sz(put_path)==1){
		path.PB(put_path[0]);
		return;
	}
	REP(i,sz(put_path)){
		ll A=put_path[i].F,B=put_path[i].S;
		build_path(A,B);
	}
}

int main(){
	ll n;cin>>n;
	REP(i,n){
		string str;cin>>str;
		v[to(str[0])][to(str[1])].PB(MP(to(str[1]),to(str[2])));
		Out[to(str[0])][to(str[1])]++;
		In[to(str[1])][to(str[2])]++;
	}
	start=MP(-1,-1),finish=MP(-1,-1);
	pll nonz=MP(-1,-1);
	REP(i,alpha){
		REP(j,alpha){
			if(In[i][j]!=0||Out[i][j]!=0)
				nonz=MP(i,j);
			if(In[i][j]!=Out[i][j]){
				if(abs(In[i][j]-Out[i][j])>1)
					NO();
				if(In[i][j]>Out[i][j]){
					if(finish.F!=-1)
						NO();
					finish=MP(i,j);
				}
				else{
					if(start.F!=-1)
						NO();
					start=MP(i,j);
				}
			}
		}
	}
	if(start.F==-1&&finish.F==-1){
		start=nonz;
		finish=nonz;
	}
	if(start.F==-1||finish.F==-1)
		NO();
	dfs(start.F,start.S);
	if(vis!=n)
		NO();
	cout<<"YES\n";
	build_path(start.F,start.S);
	cout<<from(start.F);
	REP(i,sz(path))
		cout<<from(path[i].S);
}