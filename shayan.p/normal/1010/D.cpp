// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll inf=4e18;
const ll maxn=1e6+10;
const ll mod=1e9+7;

// and or xor not

pii p[maxn];
int q[maxn],par[maxn];
bool spw[maxn][23],val[maxn];
int spl[maxn][23];
vector<int>v;

bool _calc(int kind,bool a,bool b){
    if(kind==0)return a&b;
    if(kind==1)return a|b;
    if(kind==2)return a^b;
    if(kind==3)return !a;
}

bool calc(int u){
    if(q[u]==4)return val[u];
    return (_calc(q[u],val[p[u].F],val[p[u].S]));
}

bool dfs(int u){
    if(q[u]==4)return val[u];
    if(q[u]==3)return (val[u]=!dfs(p[u].F));
    return (val[u]=_calc(q[u],dfs(p[u].F),dfs(p[u].S)));
}

int main(){
    int n;cin>>n;
    FOR(i,1,n){
	string s;cin>>s;
	int a,b;
	if(s=="AND"){
	    cin>>a>>b;
	    p[i]={a,b};
	    q[i]=0;
	    par[a]=par[b]=i;
	}
	if(s=="OR"){
	    cin>>a>>b;
	    p[i]={a,b};
	    q[i]=1;
	    par[a]=par[b]=i;
	}
	if(s=="XOR"){
	    cin>>a>>b;
	    p[i]={a,b};
	    q[i]=2;
	    par[a]=par[b]=i;
	}
	if(s=="NOT"){
	    cin>>a;
	    p[i]={a,0};
	    q[i]=3;
	    par[a]=i;
	}
	if(s=="IN"){
	    cin>>a;
	    q[i]=4;
	    val[i]=(a==1);
	    v.PB(i);
	}
    }
    dfs(1);
    FOR(i,1,n){
	spl[i][0]=par[i];
	val[i]=!val[i];
	spw[i][0]=val[par[i]]!=calc(par[i]);
	val[i]=!val[i];
    }
    FOR(j,1,21){
	FOR(i,1,n){
	    spl[i][j]=spl[spl[i][j-1]][j-1];
	    spw[i][j]=spw[i][j-1]&spw[spl[i][j-1]][j-1];
	}
    }
    REP(i,sz(v)){
	int tmp=v[i];
	bool yp=1;
	FORD(i,21,0){
	    if(spl[tmp][i]>=2){
		yp&=spw[tmp][i];
		tmp=spl[tmp][i];
	    }
	}
	yp&=spw[tmp][0];
	cout<<(val[1]^yp);
    }
}