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

const int M = 1024;

int solve(){
 		int n,k,x; cin >> n >> k >> x;
 		vector<int>fr(M);
 		rep(i,1,n+1){
 			int t;
 			cin >> t;
 			fr[t]++;
 		}
 		while(k--){
 			vector<int>new_fr(M);
 			int s = 0;
 			for(int i = 0; i < M; i++){
 				if(s%2 == 0){
 					new_fr[i] += fr[i]/2;
 					new_fr[i^x] += fr[i]/2 + fr[i]%2;
 					s += fr[i];
 				}
 				else{
 					new_fr[i] += fr[i]/2 + fr[i]%2;
 					new_fr[i^x] += fr[i]/2;
 					s += fr[i];
 				}
 			}
 			swap(new_fr,fr);
 		}
 		int mi = 0, mx = 1023;
 		while(fr[mi] == 0)mi++;
 		while(fr[mx] == 0)mx--;
 		cout << mx << " " << mi << endl;
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