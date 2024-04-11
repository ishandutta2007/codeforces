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

const int N=1e6+10;

template<typename T>
struct Fenwick{
    vector<T> tree;
    vector<T> aux;
    Fenwick(int n){
        tree.resize(n);
        aux.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    T cost(int i){
    	int sum=0;
    	while(i){
           sum+=aux[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val,T cost){
       while(i<=n){
          tree[i]+=val;
          aux[i]+=cost;
          i+=i&(-i);
       }
    }
    int fbo(int x){
    		// sum(ci)<=x
    		int L=0,R=N;
    		int pos=0;
    		while(L<=R){
    			int M=(L+R)/2;
    			if(query(M)<x){
    				pos=M;L=M+1;
    			}
    			else{
    				R=M-1;
    			}
    		}
    		assert(query(pos)<x);
    		assert(query(pos+1)>=x);
    		return cost(pos) + (pos+1)*(x-query(pos));
		    		
    }
};


vector<int>in[N],out[N];

Fenwick<int>fn(N+1);

int solve(){
 	int n,k,m;cin>>n>>k>>m;
 	vector<pii>a(m+1);
 	rep(i,1,m+1){
 		int l,r;cin>>l>>r>>a[i];
 		in[l].pb(i);
 		out[r].pb(i);
 	}
 	int ans = 0;
 	int t_cost = 0,t_av = 0;
 	rep(i,1,n+1){
 		for(auto j:in[i]){
 			int p=a[j].y;
 			int c=a[j].x;
 			fn.update(p,N,c,c*p);
 			t_av+=c,t_cost+=c*p;
 		}
 		if(t_av<=k){
 			ans+=t_cost;
 		}
 		else{
 			ans+=fn.fbo(k);
 		}
 		for(auto j:out[i]){
 			int p=a[j].y;
 			int c=a[j].x;
 			fn.update(p,N,-c,-c*p);
 			t_av-=c,t_cost-=c*p;
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