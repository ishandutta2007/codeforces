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


int solve(){
 		int n,d12,d23,d31; cin >> n >> d12 >> d23 >> d31;

 		int d_lca =(d12 + d31 - d23);

 		if(d_lca  < 0 or d_lca % 2 or d_lca/2 > d12 or d_lca/2 > d31){
 			cout << "NO" << endl;
 			return 0;
 		}
 		d_lca /= 2;
 		if(d23 + d_lca > n - 1){
 			cout << "NO" << endl;
 			return 0;
 		}
 		vector<pii>edges;
 		int j = 4;
 		if(d_lca == 0){
 			int left = d12 - 1;
 			int prev = 1;
 			while(left > 0){
 				edges.push_back({prev,j});
 				prev = j;
 				j++;
 				left--;
 			}
 			edges.push_back({prev,2});
 			int right = d31 - 1;
 			prev = 1;
 			while(right > 0){
 				edges.push_back({prev,j});
 				prev = j;
 				j++;
 				right--;
 			}
 			edges.push_back({prev,3});
 		}else{
 			if(d_lca == d12){
	 			int left = d12 - 1;
	 			int prev = 1;
	 			while(left > 0){
	 				edges.push_back({prev,j});
	 				prev = j;
	 				j++;
	 				left--;
	 			}
	 			edges.push_back({prev,2});
	 			prev = 2;
	 			int right = d23 - 1;
	 			while(right > 0){
	 				edges.push_back({prev,j});
	 				prev = j;
	 				j++;
	 				right--;
 				}
 				edges.push_back({prev,3});
 			}else if(d_lca == d31){
	 			int left = d31 - 1;
	 			int prev = 1;
	 			while(left > 0){
	 				edges.push_back({prev,j});
	 				prev = j;
	 				j++;
	 				left--;
	 			}
	 			edges.push_back({prev,3});
	 			prev = 3;
	 			int right = d23 - 1;
	 			while(right > 0){
	 				edges.push_back({prev,j});
	 				prev = j;
	 				j++;
	 				right--;
 				}
 				edges.push_back({prev,2});
 			}else{
 				int prev = 1;
 				int t = d_lca;
 				while(t--){
 					edges.push_back({prev,j});
 					prev = j;
 					j++;
 				}
 				int lca = prev;
 				t = d12 - d_lca - 1;
 				while(t > 0){
 					edges.push_back({prev,j});
 					prev = j;
 					j++;
 					t--;
 				}
 				edges.push_back({prev,2});
 				prev = lca;
 				t = d31 - d_lca - 1;
 				while(t > 0){
 					edges.push_back({prev,j});
 					prev = j;
 					j++;
 					t--;
 				}
 				edges.push_back({prev,3});
 			}
 		}
 		while(j <= n){
 			edges.push_back({j,1});
 			j++;
 		}
 		cout << "YES" << endl;
 		for(auto i:edges)cout << i << endl;

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