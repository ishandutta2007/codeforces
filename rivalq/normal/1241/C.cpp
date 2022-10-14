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
 		int n;cin>>n;
 		vector<int>v(n+1);
 		rep(i,1,n+1){
 			cin>>v[i];
 			v[i] /= 100;
 		}
 		sort(v.begin(),v.end());
 		int x,a,y,b;cin>>x>>a>>y>>b;
 		swap(x,a);swap(y,b);
 		if(a < b)swap(a,b),swap(x,y);
 		int k;cin>>k;

 		auto check=[&](int l){
 			vector<int>c(3);
 			for(int i=1;i<=l;i++){
 				if(i%x==0 and i%y==0)c[0]++;
 				else if(i%x==0) c[1]++;
 				else if(i%y==0) c[2]++;
 			}
 			vector<int>t = v;
 			int moves = 0;
 			int z = k;
 			while(z > 0 and t.size()>1){
 				int x = t.back();
 				t.pop_back();
 				moves++;
 				if(c[0]){
 					z-=(a+b)*x;
 					c[0]--;
 				}
 				else if(c[1]){
 					z-=(a)*x;
 					c[1]--;
 				}
 				else if(c[2]){
 					z-=(b)*x;
 					c[2]--;
 				}
 			}
 			if(z > 0)return -1LL;
 			else return moves;

 		};
 		
		int l=1,r=n;
		int ans = -1;
		while(l<=r){
			int m = (l+r)/2;
			auto s = check(m);
			if(s == -1){
				l = m + 1;
			}
			else{
				ans = m;
				r = m-1;
			}
		} 		
		cout << ans << endl;

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