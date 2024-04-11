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

bool isSubsequence(string s1,string s2){
     if(s1.length()>s2.length())return false;
     int i=0,j=0,n1=s1.length(),n2=s2.length();
     while(i<n1 && j<n2){
         if(s1[i]==s2[j]){
             i++;
             j++;
         }
         else{
             j++;
         }
     }
     return i==n1;
}

int solve(){
 		int n; cin >> n;
 		string s,t; cin >> s >> t;
 		int ans = n;

 		string t1 = s, t2 = t;
 		sort(all(t1));
 		sort(all(t2));
 		if(t1 != t2){
 			cout << -1 << endl;
 			return 0;
 		}

 		for(int i = 0; i <= n; i++){
 			for(int j = 0; j <= n; j++){
 				if(i + j < ans){
 					int len = n - i - j;
 					string temp = t.substr(i,len);
 					if(isSubsequence(temp,s)){
 						mins(ans,i + j);
 					}
 				}
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