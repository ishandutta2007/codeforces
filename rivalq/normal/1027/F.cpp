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

const int maxn=1000005;
int p[maxn];
int sz[maxn];
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
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}
map<int,vector<int>>vec;
set<int>st[maxn];
int solve(){
 	int n;cin>>n;
 	clear();
 	vector<pii>v(n+1);
 	rep(i,1,n+1){
 		int a,b;cin>>a>>b;
 		v[i].x=a,v[i].y=b;
 		vec[a].pb(i);
 		vec[b].pb(i);
 	}
 	for(auto i:vec){
 		int j=i.y[0];
 		for(auto k:i.y){
 			merge(k,j);
 		}
 	}
 	set<int>s;
 	int ans=0;
 	for(int i=1;i<=n;i++){
 		s.insert(root(i));
 		st[root(i)].insert(v[i].x);
 		st[root(i)].insert(v[i].y);
 	}
 	for(auto i:s){
 		if(sz[i]>st[i].size()){
 			cout<<-1<<endl;return 0;
 		}
 		int cnt=1;
 		for(auto j:st[i]){
 			if(cnt==sz[i]){
 				maxs(ans,j);
 				break;
 			}
 			cnt++;
 		}
 	}
 	cout<<ans<<endl;
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