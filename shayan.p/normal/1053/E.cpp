// Wanna Hack? GL...

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

const int maxn=2e6+10,mod=1e9+7;
const ll inf=1e18;

void No(){
    cout<<"no\n",exit(0);
}

int par[maxn],col[maxn];
int Find(int u){
    if(par[u]<0) return u;
    return par[u]=Find(par[u]);
}
void Merge(int a,int b){// a=b
    if((a=Find(a))==(b=Find(b))) return;
    if(par[a]<par[b]){
	par[a]+=par[b];
	par[b]=a;
	col[a]=col[b];
    }
    else{
	par[b]+=par[a];
	par[a]=b;
    }
}

int a[maxn],nxt[maxn],pre[maxn],lst[maxn],n;
vector<pii>v,vec,vec2;

void Merge(pii x,pii y){	
    if(col[Find(a[x.S])]<=n) swap(x,y);
    Merge(a[x.S],a[y.S]);
}

void solve(vector<pii>&vec){
    vec2.clear();
    vec2.PB(vec[0]); vec2.PB(vec[1]);
    for(int i=2;i<sz(vec)-1;i++){
	if(col[Find(a[vec[i].S])]>n && sz(vec2)>1 && col[Find(a[vec2.back().S])]<=n){
	    Merge(vec2[sz(vec2)-2],vec[i]);
	    vec2.pop_back();
	    vec2[sz(vec2)-1].S=vec[i].S;
	}
	else{
	    vec2.PB(vec[i]);
	}
    }
    vec2.PB(vec.back());
    vec.clear();
    reverse(vec2.begin(),vec2.end());
    vec.PB(vec2[0]); vec.PB(vec2[1]);
    for(int i=2;i<sz(vec2)-1;i++){
	if(col[Find(a[vec2[i].S])]>n && sz(vec)>1 && col[Find(a[vec.back().S])]<=n){
	    Merge(vec2[i],vec[sz(vec)-2]);
	    vec.pop_back();
	    vec[sz(vec)-1].F=vec2[i].F;
	}
	else{
	    vec.PB(vec2[i]);
	}
    }
    vec.PB(vec2.back());
    vec2.clear();
    reverse(vec.begin(),vec.end());
    if(col[Find(a[vec[1].S])]<=n && sz(vec)>3) No();
    vec2.PB(vec[0]);
    for(int i=1;i<sz(vec);i++){
	if(sz(vec2)>1){
	    Merge(vec2[0],vec[i]);
	    vec2.pop_back();
	    vec2[sz(vec2)-1].S=vec[i].S;
	}
	else{
	    vec2.PB(vec[i]);
	}
    }
    vec=vec2;
}

int sm[maxn];
set<int>st;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(par,-1,sizeof par);
    memset(nxt,-1,sizeof nxt);
    memset(pre,-1,sizeof pre);
    memset(lst,-1,sizeof lst);
    for(int i=0;i<maxn;i++)
	col[i]=i;
    cin>>n;
    for(int i=1;i<=n;i++)
	st.insert(i);
    int C=n;
    for(int i=0;i<2*n-1;i++){
	cin>>a[i];
	if(a[i]==0)
	    a[i]=++C;
	pre[i]=lst[a[i]];
	if(pre[i]!=-1)
	    nxt[pre[i]]=i;
	lst[a[i]]=i;
	st.erase(a[i]);
    }
    if(a[0]<=n && a[2*n-2]<=n && a[0]!=a[2*n-2]) No();
    for(int i=0;i<2*n-1;i++){
	if(pre[i]==-1){
	    v.PB({i,i});
	    continue;
	}
	vec.clear();
	vec.PB({i,i});
	while(pre[i]<v.back().S){
	    vec.PB(v.back());
	    v.pop_back();
	}
	if(v.empty() || v.back().S!=pre[i] || sz(vec)&1) No();
	vec.PB(v.back());
	int NUM=v.back().F;
	v.pop_back();
	v.PB({NUM,i});
	reverse(vec.begin(),vec.end());
	solve(vec);
    }
    if(sz(v)>1){
	Merge(v[0],v[sz(v)-1]);
       	if(col[Find(a[v[0].S])]>n){
	    for(int i=1;i<sz(v);i++){
		sm[i]=sm[i-1]+(col[Find(a[v[i].S])]<=n?1:-1);
	    }
	    int id=-1;
	    for(int i=1;i<sz(v)-1;i++){
		if((i&1)==0 && col[Find(a[v[i].S])]<=n && sm[i-1]<=1 && sm[sz(v)-2]-sm[i]<=1)
		    id=i;
	    }
	    if(id!=-1){
		Merge(v[0],v[id]);
		vec.clear();
		for(int i=0;i<=id;i++)
		    vec.PB(v[i]);
		solve(vec);
		vec.clear();
		vec.PB({0,v[id].S});
		for(int i=id+1;i<sz(v);i++)
		    vec.PB(v[i]);
		solve(vec);
	    }
	    else{
		if(st.empty()) No();
		int num=*st.begin(); st.erase(st.begin());
		col[Find(a[v[0].S])]=num;// dastkari tooyye DSU
		solve(v);
	    }
	}
	else{
	    solve(v);
	}
    }
    for(int i=0;i<2*n-1;i++){
	int num=Find(a[i]);
	if(col[num]<=n) continue;
	col[num]=*st.begin(); st.erase(st.begin());
    }
    cout<<"yes\n";
    for(int i=0;i<2*n-1;i++){
	cout<<col[Find(a[i])]<<" ";
    }
    return cout<<endl,0;
}