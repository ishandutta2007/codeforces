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
		int q = 0;
		vector<int> a(n,k);
		int p = rng()%n;
		//cin >> p;
		//p--;
		auto op = [&](){
			vector<int>b(n);
			for(int i = 0; i < n; i++){
				if(i != p){
					int f = a[i]/2;
					b[(i + 1)%n] += a[i] - f;
					b[(n + i - 1)%n] += f;
				}else{
					b[(i + 1)%n] += a[i];
				}
			}
			swap(a,b);
		};
		auto print = [&](){
			for(auto i:a)cout << i << " ";cout << endl;
		};
		auto ask = [&](int x){
			cout << "? " << x << endl << flush;
			cin >> x;
			q++;
			//x = a[x - 1];
			//op();
			return x;
		};
		auto g = [&](int ans){
			for(int j = -2; j <= 2; j++){
				int idx = ((ans + j - 1)%n + n )%n + 1;
				int idx2 = ((ans + j - 2)%n + n)%n + 1;
				int idx3 = ((ans + j)%n + n)%n + 1;
				if(ask(idx) == k and ask(idx2) < k and ask(idx3) > k){
					cout << "! " << idx << endl << flush;
					exit(0);
				}
			}
		};
		int B = 240;
		while(B--)ask(1);
		B = min(240LL,n/2 - 1);
		for(int i = 1; i <= n;){
			int st = i;
			int end = (i + 2*B - 1)%n + 1;
			auto p1 = ask(st);
			auto p2 = ask(end);
			if(p2 > p1){
				if(st > end){
					auto p1 = ask(n);
					if(p1 > p2 or p1 == k){
						int L = i;
						int R = n;
						int ans = i;
						while(L <= R){
							int M = (L + R)/2;
							auto z = ask(M);
							if(z < max(p1,p2)){
								ans = M;
								L = M + 1;
							}else{
								R = M - 1;
							}
						}
						g(ans);
						
					}else{
						int L = 1;
						int R = end;
						int ans = 1;
						while(L <= R){
							int M = (L + R)/2;
							auto z = ask(M);
							if(z < p2){
								ans = M;
								L = M + 1;
							}else{
								R = M - 1;
							}
						}
						g(ans);
					}
				}else{
						int L = st;
						int R = end;
						int ans = L;
						while(L <= R){
							int M = (L + R)/2;
							auto z = ask(M);
							if(z < p2){
								ans = M;
								L = M + 1;
							}else{
								R = M - 1;
							}
						}
						g(ans);
				}
				return 0;
			}
			i = end%n + 1;
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