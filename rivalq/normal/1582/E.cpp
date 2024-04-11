// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
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



const int N = 1e5 + 5;
vector<pii> vec[N];


int solve(){
		int n; cin >> n;
		vector<ll> a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i]; 
		} 
		reverse(a.begin() + 1,a.end());
		for(int i = 1; i <= n; i++){
			a[i] += a[i - 1];
		}
		vector<int> pos(451);
		pos[1] = 1;
		vector<ll> mn(451,0);

		for(int i = 1; i <= n; i++){
			vec[i].clear();
		}

		auto sum = [&](int i,int k) -> ll{
			return a[i] - a[i - k];
		};

		int mx = 1;
		for(int i = 1; i <= n; i++){
			for(auto j:vec[i]){
				maxs(mn[j.x],sum(j.y,j.x));
			}
			if(i + 2 <= n){
				vec[i + 2].push_back({1,i});
			}
			for(int j = 2; j <= 450; j++){
				if(2*j - 1 > i)break;
				ll s = sum(i,j);
				if(mn[j - 1] > s){
					pos[j] = 1;
					maxs(mx,j);
					if(i + j + 1 <= n){
						vec[i + j + 1].push_back({j,i});
					}
				}
			}

		}
		cout << mx << endl;


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