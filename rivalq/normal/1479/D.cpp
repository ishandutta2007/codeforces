// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


//dynamic + presistent

const int maxn=1e7;


struct node{
        int l=0,r=0;
        int sum=0;
}t[maxn];
int temp=0;
int n;



const int N = 3e5+5;

vector<int>g[N];

int w[N],a[N],d[N];
int ver[N];
int timer=0;
int in[N];
int LOG[4*N];
pii st[4*N][21];


void extend(int v){
        t[v].l=++temp;
        t[temp].sum=0;
        t[v].r=++temp;
        t[temp].sum=0;
}
void build(int v,int tl,int tr){
        t[v].sum=0;
        if(tl==tr){
               return; 
        }
        int mid=(tl+tr)/2;
        extend(v);
        build(t[v].l,tl,mid);
        build(t[v].r,mid+1,tr);
}
void update(int v,int tl,int tr,int j,int val){	
        if(tl==tr){
                t[v].sum^=val;return;
        }
        int mid=(tl+tr)/2;
        if(j<=mid){
                int old_l=t[v].l;int new_l=++temp;
                t[new_l]=t[old_l];t[v].l=new_l;
                update(t[v].l,tl,mid,j,val);
        }
        else{
            int old_r=t[v].r;int new_r=++temp;
            t[new_r]=t[old_r];t[v].r=new_r;
            update(t[v].r,mid+1,tr,j,val);
        }
        t[v].sum=t[t[v].l].sum^t[t[v].r].sum;
}
int query(int v1,int v2,int val,int l,int r,int tl=1,int tr=n){
       		if(tl>r || l>tr)return -1;
       		if(l<=tl && tr<=r){
       			int h=t[v1].sum^t[v2].sum;
       			if(val>=tl && val<=tr)h^=w[val];
       			if(h==0)return -1;
       			while(tl!=tr){
       				int h_l=t[t[v1].l].sum^t[t[v2].l].sum;
       				int mid=(tl+tr)/2;
       				if(val>=tl && val<=mid)h_l^=w[val];
       				if(h_l!=0){
       					v1=t[v1].l;
       					v2=t[v2].l;
       					tr=mid;
       				}	
       				else{
       					v1=t[v1].r;
       					v2=t[v2].r;
       					tl=mid+1;
       				}
       			}
       			return tl;
       		}
       		int mid=(tl+tr)/2;
       		int ans = query(t[v1].l,t[v2].l,val,l,r,tl,mid);
       		if(ans!=-1)return ans;
       		return query(t[v1].r,t[v2].r,val,l,r,mid+1,tr);
}

int get(int v,int j,int tl=1,int tr=n){
	if(tl==tr){
		return t[v].sum;
	}
	int mid=(tl+tr)/2;
	if(j<=mid)return get(t[v].l,j,tl,mid);
	return get(t[v].r,j,mid+1,tr);
}


void dfs(int u,int p){
	d[u]=d[p]+1;
	//cout<<u<<" "<<a[u]<<" "<<w[a[u]]<<endl;
	update(ver[u],1,n,a[u],w[a[u]]);
	//cout<<u<<" "<<t[ver[u]].sum<<endl;
	in[u] = ++timer;
	st[timer][0] = {d[u],u};
	for(auto i:g[u]){
		if(i!=p){
			ver[i]=++temp;
			t[ver[i]]=t[ver[u]];
			dfs(i,u);
			st[++timer][0]={d[u],u};
		}
	}
}

pii get_min(int l,int r){
	int j=LOG[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}	

int lca(int u,int v){
	int l=min(in[u],in[v]);
	int r=max(in[u],in[v]);
	return get_min(l,r).y;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve(){
 		int q;cin>>n>>q;
 		rep(i,1,n+1){
 			cin>>a[i];
 			w[i]=rng();
 		}
 		rep(i,0,n-1){
 			int a,b;cin>>a>>b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 		}
 		ver[1]=++temp;build(1,1,n);
 		dfs(1,1);
 		LOG[1]=0;

 		for(int i=2;i<=2*n;i++){
 			LOG[i]=1+LOG[i/2];
 		}
 		for(int x=1;x<=20;x++){
 			for(int i=1;i+(1<<x)<=2*n;i++){
 				st[i][x] = min(st[i][x-1],st[i+(1<<(x-1))][x-1]);
 			}
 		}

 		rep(i,0,q){
 			int u,v,l,r;cin>>u>>v>>l>>r;
 			int p=lca(u,v);
 			int val=a[p];
 			cout<<query(ver[u],ver[v],val,l,r)<<endl;
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