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

const int maxn=505;
const int N=10005;

struct dsu{
     int p[maxn];
     int sz[maxn];
     int cnt=0;
     void clear(int n=maxn){
         rep(i,0,n+1)p[i]=i,sz[i]=1;
         cnt=n;
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
         cnt--;
         if(sz[p1]>=sz[p2]){
             p[p2]=p1;
             sz[p1]+=sz[p2];
         }
         else{
             p[p1]=p2;
             sz[p2]+=sz[p1];
         }
     }
     dsu operator=(const dsu& d){
          for(int i=0;i<maxn;i++)this->p[i]=d.p[i],this->sz[i]=d.sz[i];
          this->cnt=d.cnt;
     }
};
dsu l[N],r[N];
int solve(){
 	int n,m;cin>>n>>m;
 	vector<pii>e(m+1);
 	rep(i,1,m+1)cin>>e[i];
 	l[0].clear(n);
 	r[m+1].clear(n);
 	for(int i=1;i<=m;i++){
 		l[i]=l[i-1];
 		l[i].merge(e[i].x,e[i].y);
 	}
 	for(int i=m;i>=1;i--){
 		r[i]=r[i+1];
 		r[i].merge(e[i].x,e[i].y);
 	}
 	int k;cin>>k;
 	rep3(k){
 		int x,y;cin>>x>>y;
 		dsu t=l[x-1];
 		for(int i=1;i<=n;i++)t.merge(i,r[y+1].root(i));
 		cout<<t.cnt<<endl;	
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