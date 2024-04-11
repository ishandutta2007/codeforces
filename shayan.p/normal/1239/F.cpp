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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

bool in[maxn], mark[maxn];
vector<int> v[maxn], vec;
int n,m;

int pr[maxn];

void compon(int u){
    in[u]=1;
    for(int y:v[u])
	if(in[y]==0)
	    compon(y);
}
void componm(int u){
    mark[u]=1;
    for(int y:v[u])
	if(sz(v[y]) % 3 == 2 && mark[y]==0)
	    componm(y);
}

int h[maxn];

bool cycle(int u,int par=-1){
    h[u]= par==-1 ? 0 : (h[par]+1);
    pr[u]=par;
    mark[u]=1;

    int tp=-1;
    for(int y:v[u]){
	if(sz(v[y]) % 3 == 1) continue;
	if(mark[y] && y!=par){
	    if(tp==-1 || h[tp]<h[y]) tp=y;
	}
    }
    if(tp!=-1){
	int tmp=u;
	while(tmp!=tp)
	    in[tmp]=1, tmp=pr[tmp];
	in[tp]=1;
	return 1;
    }
    for(int y:v[u]){
	if(sz(v[y]) % 3 == 1) continue;
	if(mark[y]==0){
	    if(cycle(y,u))
		return 1;
	}
    }
    return 0;
}

bool path(int src){
    queue<int> q;
    q.push(src);
    mark[src]=1;

    while(sz(q)){
	int u=q.front();
	q.pop();
	
	if(u != src && sz(v[u]) % 3 ==1){
	    int tmp=u;
	    while(tmp!=src)
		in[tmp]=1, tmp=pr[tmp];
	    in[src]=1;
	    return 1;
	}	
	for(int y:v[u]){
	    if(mark[y]==0)
		mark[y]=1, pr[y]=u, q.push(y);	
	}
    }
    return 0;
}
bool dis(int u,int par=-1){
    pr[u]=par;
    mark[u]=1;
    if(par!=-1 && sz(v[u])>=3){
	int tmp=u;
	while(tmp!=-1)
	    vec.PB(tmp), tmp=pr[tmp];
	return 1;
    }
    for(int y:v[u]){
	if(sz(v[y]) % 3 == 2 && mark[y]==0){
	    if(dis(y,u))
		return 1;
	}
    }
    return 0;
}

void go(int u,int par=-1){
    for(int y:v[u]){
	if(y==par || sz(v[y]) % 3 == 1) continue;
	go(y,u);
    }
    in[u]=1;
}
bool fnd(int u,int par=-1){
    bool way=0;
    for(int y:v[u]){
	way|= sz(v[y]) % 3 == 1;
    }
    for(int y:v[u]){
	if(y==par || sz(v[y]) %3 == 1) continue;
	if(fnd(y,u)) return 1;
    }
    int cnt=0;
    for(int y:v[u]){
	if(y==par || sz(v[y]) %3 == 1) continue;
	if(++cnt == 2-way) break;
    }
    if(cnt == 2-way){
	cnt=0;
	in[u]=1;
	for(int y:v[u]){
	    if(y==par || sz(v[y]) %3 == 1) continue;
	    go(y,u);
	    if(++cnt == 2-way) break;
	}
	return 1;
    }
    return 0;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
	v[i].clear();
	in[i]=0;
    }
    for(int i=0;i<m;i++){
	int a,b; cin>>a>>b;
	v[--a].PB(--b);
	v[b].PB(a);
    }
    for(int i=0;i<n;i++){
	if(sz(v[i]) % 3 == 0){
	    in[i]=1;
	    return;
	}
    }
    for(int i=0;i<n;i++){
	for(int j:v[i]){
	    if((sz(v[i]) % 3 == 1) && (sz(v[j]) % 3 == 1)){
		in[i]= in[j]= 1;
		return;
	    }
	}
    }
    compon(0);
    for(int i=0;i<n;i++){
	if(in[i]==0)
	    return;
    }
    fill(in,in+n,0);
    fill(mark,mark+n,0);

    for(int i=0;i<n;i++){
	if((sz(v[i]) % 3) == 2 && mark[i]==0 && cycle(i))
	    return;
    }
    int id=-1;
    for(int i=0;i<n;i++){
	if(sz(v[i]) % 3 == 1)
	    id=i;
    }
    if(id==-1) return;

    fill(mark,mark+n,0);
    if(path(id)) return;
   
    in[id]=1;
    
    fill(mark,mark+n,0);

    bool any=0;
    
    for(int i=0;i<n;i++){
	if(i!=id && mark[i]==0){
	    fnd(i);
	    componm(i);
	    break;
	}
    }
    for(int i=0;i<n;i++){
	if(i!=id && mark[i]==0){
	    fnd(i);
	    any=1;
	    break;
	}
    }
    if(any) return;
    
    fill(in,in+n,0);
    fill(mark,mark+n,0);
    
    vec.clear();
    for(int i=0;i<n;i++){
	if(i != id && mark[i]==0 && sz(v[i])>=3 && dis(i))
	    break;
    }
    if(vec.empty()) return;
    
    in[id]=1;
    fnd(vec[0],vec[1]);
    fnd(vec.back(), vec[sz(vec)-2]);
    
    if(sz(vec)==2 && in[vec[0]] && in[vec[1]]){
	fill(in,in+n,0);
	return;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    vector<int> ans;

    int q; cin>>q;
    while(q--){
	solve();
	ans.clear();
	for(int i=0;i<n;i++)
	    if(in[i]==0)
		ans.PB(i+1);
	if(sz(ans)!=0 && sz(ans)!=n){
	    cout<<"Yes\n";
	    cout<<sz(ans)<<"\n";
	    for(int u:ans)
		cout<<u<<" ";
	    cout<<"\n";		
	}
	else{
	    cout<<"No\n";
	}
    }
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")