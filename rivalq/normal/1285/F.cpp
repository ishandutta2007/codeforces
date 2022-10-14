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


const int N = 2e5;

bool used[N];

vector<int>d[N];


int cnt[N],mobius[N];

#define SIEVE


int lp[N+1];
int pr[N];int t=0;

void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    mobius[1] = 1;
    for(int i = 2; i < N; i++){
    		if(lp[i/lp[i]] == lp[i]) {
    			mobius[i] = 0;
    		}
    		else{
    			mobius[i] = -1 * mobius[i/lp[i]];
    		}
    }

}







int solve(){
 		int n; cin >> n;

 		vector<int> a(n+1);

 		vector<int>t;


 		rep(i,1,n+1){
 			cin >> a[i];
 			if(!used[a[i]]){
 				for(auto j:d[a[i]]){
 					if(!used[j]){
 						used[j] = 1;
 						t.push_back(j);
 					}	
 				}
 			}
 		}
 		// max product of two coprime numbers

 		auto coprime = [&](int x) -> int{

 			int res = 0;

 			for(auto i:d[x]){
 				res += mobius[i]*cnt[i];
 			}

 			return res;
 		};

 		auto update = [&](int x,int val) -> void{

 			for(auto i:d[x]){
 				cnt[i] += val;
 			}

 		};

 		sort(t.begin(),t.end(),greater<int>());
 		
 		vector<int>mx;

 		int ans = 1;

 		for(auto i:t){
 			while(coprime(i)){
 				int j = mx.back();
 				mx.pop_back();
 				if(gcd(j,i)==1){
 					maxs(ans,i*j);
 				}
 				update(j,-1);
 			}
 			mx.push_back(i);
 			update(i,1);
 		}

 		cout << ans << endl;	


 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=1;i<=1e5;i++){
    	for(int j=i;j<=1e5;j+=i){
    		d[j].push_back(i);
    	}
    }
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