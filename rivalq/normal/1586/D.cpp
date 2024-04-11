// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
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
 		vector<int> a(n + 1);

 		vector<int> ans(n + 1),ans2(n + 1);

 		auto query = [&](int x,int val){
 			cout << "? ";
 			for(int i = 1; i <= n; i++){
 				if(i == x){
 					cout << val << " ";
 				}else{
 					cout << 1 << " ";
 				}
 			}
 			cout << endl << flush;
 			cin >> x;
 			return x;
 		};

 		vector<int> pos(n + 1);

 		for(int i = 1; i <= n; i++){
 			ans[i] = query(i,2);
 			if(ans[i] == 0){
 				pos[n] = i;
 			}
 		}
 		
 		for(int i = n - 1; i >= 1; i--){
			cout << "? ";
			for(int j = 1; j <= n; j++){
				if(j == pos[i + 1]){
					cout << 1 << " ";
				}else{
					cout << 2 << " ";
				}
			}
			cout << endl << flush;
			int x; cin >> x;
			if(x == pos[i + 1]){
				//cout << "#" << i << endl;
				for(int j = 1; j <= n; j++){
					if(ans[j] == pos[i + 1] and j != pos[i + 1]){
						pos[i] = j;
						break;
					}
				}

	
			}else{
				pos[i] = x;
			}
			//cout << "@" << pos[i] << endl;
					
 		}
 		vector<int>p(n + 1);
 		for(int i = 1; i <= n; i++){
 			p[pos[i]] = i;
 		}
 		cout << "! ";
 		for(int i = 1; i <= n; i++){
 			cout << p[i] << " ";
 		}
 		cout << endl << flush;

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
// 3 2 1 5 4