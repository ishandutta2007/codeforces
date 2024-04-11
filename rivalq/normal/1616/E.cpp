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

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};


int solve(){
		int n; cin >> n;
 		string s,t; cin >> s >> t;
 		string t2 = s;
 		sort(all(t2));
 		if(t2 >= t){
 			cout << -1 << endl;
 			return 0;
 		}
 		vector<queue<int>>vec(26);
 		for(int i = 0; i < n; i++){
 			vec[s[i] - 97].push(i + 1);
 		}
 		Fenwick<int> fn(n + 1);
 		for(int i = 1; i <= n; i++){
 			fn.update(i,n,1);
 		}
 		int ans = 1e15;
 		int calc = 0;
 		for(int i = 1; i <= n; i++){
 			int val = 1e15;
 			for(int j = 0; j < t[i - 1] - 97; j++){
 				if(vec[j].size() > 0){
 					int k = vec[j].front();
 					mins(val,fn.query(k) - 1);
 				}
 			}
 			mins(ans,calc + val);
 			if(vec[t[i - 1] - 97].size() == 0)break;
 			int k = vec[t[i - 1] - 97].front();
 			calc += fn.query(k) - 1;
 			vec[t[i - 1] - 97].pop();
 			fn.update(k,n,-1);
 		}
 		cout << ans << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}