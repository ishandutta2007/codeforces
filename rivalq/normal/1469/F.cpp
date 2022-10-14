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


const int N = 1e6+5;

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        i++;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,T val,int n=N){
       i++;
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};


Fenwick<int>fn(N+1);


int d_add[N];

int solve(){
 	int n,k;cin>>n>>k;
 	vector<int>a(n+1);
 	int at_max=1;
 	rep(i,1,n+1){
 		cin>>a[i];
 		at_max+=a[i]-2;
 	}
 	if(at_max<k){
 		cout<<-1<<endl;return 0;
 	}
 	sort(a.begin()+1,a.end(),greater<int>());
 	fn.update(0,1);
 	fn.update(1,-1);
 	int j=0;
 	rep(i,1,n+1){
 		while(fn.query(j)==0)j++;
 		d_add[i]=j;
 		a[i]--;
 		fn.update(j,-1);fn.update(j+1,1);
 		int x=a[i]/2;
 		int y=a[i]/2+(a[i]%2);
 		// j+2....j+2+x-1;
 		fn.update(j+2,1);fn.update(j+2+x,-1);
 		fn.update(j+2,1);fn.update(j+2+y,-1);
 	}
 	auto check=[&](int ans){
 		int add=1;
 		rep(i,1,n+1){
 			int j=d_add[i];
 			add--;
 			if(j>=ans)return 0;
 			int x=a[i]/2;
 			int y=a[i]/2+(a[i]%2);
 			//j+2...ans..j+2+x-1
 			if(ans>=j+2){
 				add+=min(j+1+x,ans)-j-1;
 				add+=min(j+1+y,ans)-j-1;
 			}
 			if(add>=k)return 1;
 		}
 		return 0;
 	};
 	int L=1,R=N;
 	int ans=N;
 	while(L<=R){
 		int M=(L+R)/2;
 		if(check(M)){
 			ans=M;
 			R=M-1;
 		}
 		else{
 			L=M+1;
 		}
 	}
 	//assert(ans<N);
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