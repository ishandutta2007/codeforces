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
template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum^=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]^=val;
          i+=i&(-i);
       }
    }
};


int solve(){
 	int n;cin>>n;
 	Fenwick<int> fn(n+1);
 	vector<int>a(n+1),p(n+1);
 	rep(i,1,n+1)cin>>a[i],p[i]=a[i]^p[i-1];
 	map<int,int>mp;
 	int m;cin>>m;
 	vector<pair<int,pii>>q(m);
 	vector<int>ans(m);
 	rep3(m){
 		cin>>q[i].y.x>>q[i].x;
 		q[i].y.y=i;
 	}sort(all(q));
 	int j=0;		
 	rep(i,1,n+1){
 			if(mp.count(a[i])){
 					fn.update(mp[a[i]],n,a[i]);
 					fn.update(i,n,a[i]);
 					mp[a[i]]=i;
 			}
 			else{
 				       fn.update(i,n,a[i]);
 				       mp[a[i]]=i;
 			}
 			while(j<m && q[j].x==i){
 					ans[q[j].y.y]=fn.query(q[j].x)^fn.query(q[j].y.x-1)^p[q[j].x]^p[q[j].y.x-1];
 					j++;
 			}
 	}
 	rep3(m)cout<<ans[i]<<endl;
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