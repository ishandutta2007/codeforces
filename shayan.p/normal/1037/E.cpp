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

const int maxn=2e5+10;

pii p[maxn];
set<int>v[maxn];
set<pii>gd;

int dg[maxn],ans[maxn],n,m,k;

void Delete(int x,int y){
    if(!v[x].count(y))return;
    pii P1={dg[x],x},P2={dg[y],y};
    if(gd.count(P1)){
	gd.erase(P1);
	dg[x]--;P1.F--;
	gd.insert(P1);
    }
    if(gd.count(P2)){
	gd.erase(P2);
	dg[y]--;P2.F--;
	gd.insert(P2);
    }
    v[x].erase(y);
    v[y].erase(x);
}

void normal(){
    while(sz(gd) && (gd.begin()->F)<k){
	int u=gd.begin()->S;
	while(sz(v[u]))
	    Delete(u,*v[u].begin());
	gd.erase({0,u});
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,m){
	scanf("%d%d",&p[i].F,&p[i].S);
	dg[p[i].F]++;
	dg[p[i].S]++;
	v[p[i].F].insert(p[i].S);
	v[p[i].S].insert(p[i].F);
	
    }

    
    FOR(i,1,n){
	gd.insert({dg[i],i});
    }
    
    normal();
    
    REPD(i,m){
	ans[i]=sz(gd);
	Delete(p[i].F,p[i].S);
	normal();
    }
    REP(i,m){
	printf("%d\n",ans[i]);
    }
}