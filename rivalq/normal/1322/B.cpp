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

template<typename T>
struct Fenwick{
    vector<T> tree;
    int M=0;
    int sz=0;
    void resize(int n,int m){
        tree.resize(n,0);
        M=m;
        sz=n;
    }

    T query(int i){
        int sum=0;
        i++;
        while(i>0){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,T val){
    	i++;	
       while(i<sz){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
    int query(int l,int r){
    		r=min(r,M);
    		l=max(0,l);
    		if(l>r)return 0;
    		return query(r)-query(l-1);
    }
};



struct add_xor{
	Fenwick<int>fn[25];
	add_xor(){
		int sz=1;
		for(int i=0;i<25;i++){
			sz*=2;
			fn[i].resize(sz+2,sz);
		}
	}
	void insert(int x){
		int sz=1;
		for(int i=0;i<25;i++){
			sz*=2;
			int val=x%sz;
			fn[i].update(val,1);
		}
	}
	void erase(int x){
		int sz=1;
		for(int i=0;i<25;i++){
			sz*=2;
			int val=x%sz;
			fn[i].update(val,-1);
		}
	}
	int query(int x){
		int sz=1;
		int ans=0;
		for(int i=0;i<25;i++){
			sz*=2;
			int val=x%sz;
			int cnt=fn[i].query(sz/2-val,sz-1-val)+fn[i].query(sz/2+sz-val,2*sz-2-val);
			if(cnt%2)ans+=(1<<i);
		}
		return ans;
	}	
}st;


int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 		st.insert(a[i]);
 	}
 	int x=0;
 	for(int i=1;i<=n;i++){
 		st.erase(a[i]);
 		x^=st.query(a[i]);
 	}
 	cout<<x<<endl;
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