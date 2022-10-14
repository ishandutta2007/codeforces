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
 		int n; cin >> n;
 		vector<set<int>> vec(n + 1);
 		vector<int> a(n + 1);
 		vector<int> b(n + 1);
 		vector<int> fr(n + 1);
 		int mx = 0;
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			b[i] = a[i];
 			vec[a[i]].insert(i);
 			fr[a[i]]++;
 			maxs(mx,fr[a[i]]);
 		}
 		sort(all(b));
 		auto rotate = [&](int x,int y,int z){
 			int val1 = a[x];
 			int val2 = a[y];
 			int val3 = a[z];
 			vec[val1].erase(x);
 			vec[val2].erase(y);
 			vec[val3].erase(z);
 			vec[val1].insert(y);
 			vec[val2].insert(z);
 			vec[val3].insert(x);
 			a[y] = val1;
 			a[z] = val2;
 			a[x] = val3;
 		};
 		auto pop = [&](int val){
 			vec[val].erase(*vec[val].begin());
 		};

 		for(int i = 1; i + 2 <= n; i++){
 			int val = b[i];
 			if(*vec[val].begin() == i){
 				pop(val);
 			}else if(*vec[val].begin() == i + 1){
 				int x = i;
 				int y = i + 1;
 				int z = i + 2;
 				rotate(x,y,z);
 				rotate(x,y,z);
 				assert(a[i] == b[i]);
 				pop(val);
 			}else{
 				int x = i;
 				int y = i + 1;
 				int z = *vec[val].begin();
 				rotate(x,y,z);
 				assert(a[i] == b[i]);
 				pop(val);
 			}
 		}
 		if(a == b){
 			cout << "YES" << endl;
 		}else{
 			if(mx > 1){
 				cout << "YES" << endl;
 			}
 			else{
 				cout << "NO" << endl;
 			}	
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