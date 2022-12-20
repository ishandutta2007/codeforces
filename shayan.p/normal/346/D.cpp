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

const int maxn=1e6+10;

vector<int>v[maxn],g[maxn],v1,v2;
queue<int>zr;
int ds[maxn],dg[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	g[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	dg[i]=sz(v[i]);
    }
    int s,t;cin>>s>>t;
    ds[t]=1;
    v1.PB(t);
    int nw=1;
    while(!v1.empty()){
	for(int i=0;i<sz(v1);i++){
	    for(int y:g[v1[i]]){
		if(ds[y]==0 && (--dg[y])==0)
		    ds[y]=nw,v1.PB(y);
	    }
	}
	v2.clear();
	for(int u:v1){
	    for(int y:g[u]){
		if(ds[y]==0)
		    ds[y]=nw+1,v2.PB(y);
	    }
	}
	swap(v1,v2);
	nw++;
    }
    cout<<ds[s]-1<<endl;
    return 0;
}