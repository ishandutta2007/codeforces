#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	string s;cin>>s;
 	vector<int>a(26,0);
 	for(int i=0;i<s.length();i++){
 		a[s[i]-97]++;
 	}
 	int m;cin>>m;
 	vector<int>b(m);
 	vector<int>v;
 	rep3(m){
 		cin>>b[i];
 	}
 	string ans(m,'0');
 	int cnt=0;
 	while(cnt<m){
 		vector<int>temp;
 		for(int j=0;j<m;j++){
 			if(ans[j]=='0'){
 				int a=0;
 				for(auto x:v){
 					a+=(abs(x-j));
 				}
 				assert(b[j]>=a);
 				if(b[j]==a){
 					temp.pb(j);
 				}
 			}
 		}
 		assert(sz(temp));
 		for(int j=25;j>=0;j--){
 			if(a[j]>=sz(temp)){
 				for(auto x:temp){
 					ans[x]=j+97;
 					v.pb(x);
 				}				
 				a[j]=0;
 				break;
 			}
 			else{
 				a[j]=0;
 			}
 		
 		}
 		assert(cnt!=sz(v));
 		cnt=sz(v);
 	}
 	cout<<ans<<endl;
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