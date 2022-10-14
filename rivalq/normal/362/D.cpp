#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
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


const int maxn=2000005;
int p[maxn];
int sz[maxn];
int w[maxn];
int cnt=0;
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y,int v){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2){
    	w[p1]+=v;return;
    }
    if(sz[p1]<sz[p2])swap(p1,p2);
    p[p2]=p1;
    sz[p1]+=sz[p2];
    w[p1]+=w[p2];
    w[p1]+=v;
    cnt--;
}

const int inf=1e9;

int solve(){
 	int n,m,p,q;cin>>n>>m>>p>>q;
 	cnt=n;
 	clear();
 	pii edge;
 	rep(i,0,m){
 		int a,b,v;cin>>a>>b>>v;
 		edge.x=a,edge.y=b;
 		merge(a,b,v);
 	}
 	if(cnt<q || cnt-p>q){
 		cout<<"NO"<<endl;return 0;
 	}
 	set<pair<int,int>>st;
 	vector<pii>ans;
 	rep(i,1,n+1){
 		if(root(i)==i){
 			st.insert({w[i],i});
 		}
 	}
 	while(cnt>q){
 		pii p1=*st.begin();st.erase(st.begin());
 		pii p2=*st.begin();st.erase(st.begin());
 		ans.eb(root(p1.y),root(p2.y));
 		merge(p1.y,p2.y,min(inf,p1.x+p2.x+1));
 		st.insert({w[root(p1.y)],p1.y});
 	}
 	if(ans.empty() && m==0 && p>0){
 		cout<<"NO"<<endl;return 0;
 	}
 	cout<<"YES"<<endl;
 	if(ans.empty() && p)ans.pb(edge);
 	while(sz(ans)<p){
 		ans.pb(ans.back());
 	}
 	for(auto i:ans)cout<<i<<endl;
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