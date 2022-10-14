#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


struct dsu_save{
	int u,v; 
	vector<int>s;
};
stack<dsu_save>stk;
const int N=5e5+5;
int par[N];
priority_queue<pii>st[N];
vector<int>vec[N];
bool joined[N];
int a[N];
pii queries[N];
pii edges[N];
bool mark[N];
int sz[N];
int root(int x){
	return (x==par[x])?x:root(par[x]);
}
bool unite(int u,int v){
	int p=root(u);
	int q=root(v);
	if(p==q)return 0;
	if(sz[p]<sz[q])swap(p,q);
	vector<int>temp;
	for(auto i:vec[q])temp.pb(i);
	for(auto i:vec[q])vec[p].pb(i);
	stk.push({p,q,temp});
	par[q]=p;
	sz[p]+=sz[q];
	return 1;

}

void rollback(){
	if(stk.empty())return;
	dsu_save save=stk.top();
	stk.pop();
	par[save.u]=save.u;
	par[save.v]=save.v;
	for(auto i:save.s){
		st[save.v].push({a[i],i});
	}
}

int getans(int x){
	int p=root(x);
	while(!st[p].empty() && root(st[p].top().y)!=p){
		st[p].pop();
	}
	if(st[p].empty())return 0;
	pii s=st[p].top();
	st[p].pop();
	a[s.y]=0;
	return s.x;
}

int solve(){
 	int n,m,q;cin>>n>>m>>q;
 	rep(i,1,n+1)cin>>a[i];
 	rep(i,1,n+1)par[i]=i,sz[i]=1,vec[i].pb(i);
 	vector<pair<pii,int>>del;
 	rep(i,1,m+1){
 		cin>>edges[i];
 	}
 	rep(i,1,q+1){
 		cin>>queries[i];
 		if(queries[i].x==2){
 			mark[queries[i].y]=1;
 			del.pb({edges[queries[i].y],i});
 		}
 	}	
 	rep(i,1,m+1){
 		if(!mark[i]){
 			unite(edges[i].x,edges[i].y);
 		}
 	}
 	reverse(all(del));
 	for(auto i:del){
 		joined[i.y]=unite(i.x.x,i.x.y);
 	}
 	rep(i,1,n+1)st[root(i)].push({a[i],i});
 	rep(i,1,q+1){
 		if(queries[i].x==1){
 			cout<<getans(queries[i].y)<<endl;
 		}
 		else{
 			if(joined[i]){
 				//cout<<i<<endl;
 				rollback();
 			}
 		}
 	}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}