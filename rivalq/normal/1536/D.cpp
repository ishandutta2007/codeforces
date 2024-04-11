// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

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
 		int n; cin >> n;
 		vector<int>a(n+1);
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		int key = 0;
 		int neg = -1e12;
 		int pos = 1e12;
 		if(n <= 2){
 			cout << "YES" << endl;
 			return 0;
 		}else{
 			Tree<pii> tr;
 			tr.insert({a[1],++key});
 			if(a[2] < a[1]){
 				tr.insert({neg,++key});
 				tr.insert({a[2],++key});
 			}else if(a[1] < a[2]){
 				tr.insert({pos,++key});
 				tr.insert({a[2],++key});
 			}else{
 				tr.insert({neg,++key});
 				tr.insert({pos,++key});
 			}
 			for(int i = 3; i <= n; i++){
 				int ord = i - 2;
 				auto itr = tr.fbo(ord);
 				auto itr2 = itr;itr2++;
 				auto itr3 = itr;itr3--;

				if(a[i] > itr2 -> x){
					cout << "NO" << endl;
					return 0;
				}
				if(a[i] < itr3->x){
					cout << "NO" << endl;
					return 0;
				}
				if(itr2 ->x == a[i]){
					tr.insert({pos,++key});
					tr.insert({pos,++key});
				}
				else if(itr3 -> x == a[i]){
					tr.insert({neg,++key});
					tr.insert({neg,++key});
				}else{
					if(itr -> x > a[i]){
						tr.insert({neg,++key});
					        tr.insert({a[i],++key});

					}else if(itr -> x < a[i]){
						tr.insert({pos,++key});
						tr.insert({a[i],++key});

					}else{
						tr.insert({pos,++key});
						tr.insert({neg,++key});
					}
				}
				//for(auto i:tr)cout << i.x << " ";
 				//cout << endl;
				
 			}
 			
 			cout << "YES" << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}