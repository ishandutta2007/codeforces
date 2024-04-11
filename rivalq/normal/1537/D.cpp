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



map<int,int>mp;


int grundy(int n){
	set<int>st;
	if(mp.count(n))return mp[n];
	for(int j = 2; j <= sqrt(n); j++){
		if(n%j == 0){
			st.insert(grundy(n - n/j));
			st.insert(grundy(n - j));
		}
	}
	for(int j = 0;;j++){
		if(st.count(j) == 0)return mp[n] = j;
	}
}

int solve(){
 	
		int n; cin >> n;
		int cnt = 0;
		while(n%2 == 0){
			cnt++;
			n /= 2;
		}
		if(cnt == 0){
			cout << "Bob" << endl;
		}else if(n > 1){
			cout << "Alice" << endl;
		}else if(cnt%2){
			cout << "Bob" << endl;
		}else{
			cout << "Alice" << endl;
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