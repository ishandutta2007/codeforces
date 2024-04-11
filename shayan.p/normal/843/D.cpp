// Phoenix

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
typedef pair<int,ll> pil;

const int maxn=1e5+10,maxw=1e6+10;
const ll inf=4e18;

int n,m,added;
pii p[maxn];
vector<pil>v[maxn];
ll ds[maxn],mr[maxn];

void calc(){
    priority_queue<pll,vector<pll>,greater<pll> >pq;
    fill(ds,ds+maxn,inf);
    pq.push({0,0});
    ds[0]=0;
    while(!pq.empty()){
	int u=pq.top().S;
	ll x=pq.top().F;
	pq.pop();
	if(ds[u]<x) continue;
	for(pil p:v[u]){
	    if(x+p.S<ds[p.F])
		ds[p.F]=x+p.S,pq.push({ds[p.F],p.F});
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<sz(v[i]);j++)
	    v[i][j].S-=ds[v[i][j].F]-ds[i];
    }
}

vector<int>q[maxw];

void recalc(){
    if(added==0) return;
    fill(mr,mr+maxn,inf);
    mr[0]=0;
    q[0].PB(0);
    for(int i=0;i<=added;i++){
	for(int j=0;j<sz(q[i]);j++){
	    int u=q[i][j];
	    if(mr[u]<i) continue;
	    for(pil p:v[u]){
		if(i+p.S<mr[p.F]){
		    mr[p.F]=i+p.S;
		    if(mr[p.F]<=added)
			q[mr[p.F]].PB(p.F);
		}
	    }
	}
	q[i].clear();
    }
    added=0;
    for(int i=0;i<n;i++){
	for(int j=0;j<sz(v[i]);j++)
	    v[i][j].S-=mr[v[i][j].F]-mr[i];
	if(ds[i]!=inf)
	    ds[i]+=mr[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int q;cin>>n>>m>>q;
    for(int i=0;i<m;i++){
	int a,b,c;cin>>a>>b>>c;
	--a;--b;
	p[i]={a,sz(v[a])};
	v[a].PB({b,c});
    }
    calc();
    while(q--){
	int task,x;cin>>task>>x;
	if(task==1){
	    recalc();
	    cout<<(ds[--x]==inf?-1:ds[x])<<"\n";
	}
	else{
	    added+=x;
	    while(x--){
		int y;cin>>y;
		--y;
		v[p[y].F][p[y].S].S++;
	    }
	}
    }
    return 0;
}