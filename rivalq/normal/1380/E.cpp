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
set<int>s[maxn];
int p[maxn];
int sz[maxn];
int ans=0;
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=sz(s[i]);
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
    if(sz[p1]<sz[p2])swap(p1,p2);
	p[p2]=p1;
	sz[p1]+=sz[p2];
	for(auto i:s[p2]){
		if(s[p1].count(i+1))ans--;
		if(s[p1].count(i-1))ans--;
	}
	for(auto i:s[p2])s[p1].insert(i);
	s[p2].clear();	
    
}



int solve(){
 	int n,m;cin>>n>>m;
 	vector<int>t(n+1);
 	rep(i,1,n+1){
 		cin>>t[i];
 		s[t[i]].insert(i);
 	}
 	clear(m);
 	rep(i,1,n){
 		if(t[i]!=t[i+1])ans++;
 	}
 	cout<<ans<<endl;
 	rep3(m-1){
 		int a,b;cin>>a>>b;
 		merge(a,b);
 		cout<<ans<<endl;
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