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
 	int n,k;cin>>n>>k;
 	string s;cin>>s;
 	int x=s.back()-97;s.pop_back();
 	k-=(1LL<<x);
 	x=s.back()-97;s.pop_back();
 	k+=(1LL<<x);
 	int sum=0;
 	vector<int>cnt(62);
 	for(int i=0;i<s.length();i++){
 		int x=s[i]-97;
 		cnt[x+1]++;
 		sum+=(1LL<<x);
 	}
 	int d=sum-k;
 	for(int j=0;j<60;j++){
 		int v=(1LL<<j);
 		if(v&d){
 			if(cnt[j]==0){
 				cout<<"No";exit(0);
 			}
 			cnt[j]--;
 		}
 		cnt[j+1]+=cnt[j]/2;
 	}
 	cout<<"Yes";
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