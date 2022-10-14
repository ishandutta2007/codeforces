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
 		int n,q; cin >> n >> q;
 		map<pii,int>mp;
 		

 		auto update = [&](int i,int l,int r){
 			
 			while(l < r){
 				mp[{l,r}]--;
 				int mid = (l + r)/2;
 				if(i <= mid){
 					r = mid;
 				}
 				else{
 					l = mid + 1;
 				}
 			}
 			mp[{i,i}] = 0;
 		};
 		

 		auto ask = [&](int l,int r){
 			if(mp.count({l,r})){
 				return mp[{l,r}];
 			}
 			cout << "? " << l << " " << r << endl << flush;
			int x; cin >> x;
			mp[{l,r}] = (r - l + 1) - x;
			return mp[{l,r}];
 		};
 		int cnt = 0;
 		for(int i = 0; i < q; i++){
 				int k;
 				cin >> k;
 				int L = 1, R = n;
 				int a = -1;
 				ask(1,n);
 				while(L < R){
 					int mid = (L + R)/2;
 					int x = ask(L,mid);
 					mp[{mid+1, R}] = mp[{L,R}] - x;

 					if(x < k){
 						L = mid + 1;
 						k -= x;
 					}
 					else{
 						R = mid;
 					}
 				}
 				a = L;
 				update(a,1,n);
 				cout << "! "<< a << endl << flush;
 				
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