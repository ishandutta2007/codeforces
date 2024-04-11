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


int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}


int solve(){
 		int q; cin >> q;

 		vector<int>shift(61,0);
 		vector<int>mod(61,1);

 		rep(i,1,60){
 			mod[i] = 2*mod[i-1];
 		}

 		auto get_level = [&](int x){
 			for(int j = 60; j >= 0; j--){
 				if((1LL<<j)&x){
 					return j;
 				}
 			}
 			return 0LL;
 		};

 		auto update = [&](int l,int k){
 			int cnt = 0;
 			for(int j = l; j <= 60; j++){
 				int num = mod[j];
 				int new_k = k%mod[l];
 				new_k = new_k*(1LL<<cnt);
 				shift[j] += new_k;
 				shift[j] %= num;
 				shift[j] = (shift[j] + num)%num; 
 				cnt++;
 			}
 		};	

 		auto get_value = [&](int l,int j){
 			// a[j - shift[l] ] 
 			int k = j - shift[l];
 			k %= mod[l];
 			k = (k + mod[l])%mod[l];
 			return mod[l] + k;
 		};

 		while(q--){
 			int t; cin >> t;
 			if(t == 1){
 				int x,k; cin >> x >> k;
 				int j = get_level(x);
 				int num = 1LL<<j;
 				shift[j] = (shift[j] + k)%num;
 				shift[j] = (shift[j] + num)%num;
 			}
 			else if(t == 2){
 				int x,k; cin >> x >> k;
 				update(get_level(x),k);
 			}
 			else{
 				vector<int>v;
 				int x; cin >> x;
 				int l = get_level(x);
 				int k = x - mod[l] + shift[l];
 				k = k%mod[l];
 				while(l >= 0){
 					cout << get_value(l,k) << " ";
 					k /= 2;
 					l--;
 				}
 				cout << endl;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}