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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve(){
		int n,k; cin >> n >> k;

		

		vector<int> grey = {0,1};
		int val = 2;
		while(grey.size() != 32){
			vector<int> temp = grey;
			for(auto &i:temp)i += val;
			reverse(all(temp));
			for(auto i:temp)grey.push_back(i);
			val *= 2;
		}
	        vector<int> nums(32),nums2(32);
		int res = 0;
		for(int i = 0; i < 32; i++){
			for(int j = 0; j < 5; j++){
				if((1 << j) & i){
					nums[i] += (1 << (2*j));
				}
			}
			nums2[i] = nums[i]*2;
		}
		vector<int> t1(32),t2(32);
		for(int i = 0; i < 32; i++){
			t1[i] = nums[grey[i]];
			t2[i] = nums2[grey[i]];
		}
		vector<vector<int>>a(n,vector<int>(n));

		for(int i = 0; i < n; i++){
			for(int j = 0; j  < n; j++){
				a[i][j] = t1[i]^t2[j];
				if(i > 0)res += a[i][j]^a[i - 1][j];
				if(j > 0)res += a[i][j]^a[i][j - 1];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 1; j < n; j++){
				cout << (a[i][j]^a[i][j - 1]) << " ";
			}
			cout << endl << flush;
		}
		for(int i = 1; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << (a[i][j]^a[i - 1][j]) << " ";
			}
			cout << endl << flush;
		}
		assert(res <= 48000);
		int x = 0,y = 0;
		while(k--){
			int w; cin >> w;
			w ^= a[x][y];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(a[i][j] == w){
						x = i,y = j;
						break;
					}
				}
			}
			cout << x + 1<< " " << y + 1 << endl << flush;
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