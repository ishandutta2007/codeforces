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
 	vector<pii>ans;
 	vector<int>p(n+1);
 	rep(i,1,n+1){
 		p[i]=i;
 	}	
 	int sec=0;
 	ans.push_back({1,n});swap(p[1],p[n]);
 	int r=n-1;
 	int l=2;
 	while(l<=r){
 		if(l==r){
 			swap(p[l],p[1]);
 			ans.push_back({l,1});break;
 		}
 		else{
 			swap(p[n],p[l]);
 			swap(p[r],p[1]);
 			ans.push_back({l,n});
 			ans.push_back({r,1});
 			l++;
 			r--;
 		}
 	}
 	for(auto i:ans){
 		sec+=(i.x-i.y)*(i.x-i.y);
 	}cout<<sec<<endl;
 	rep(i,1,n+1)cout<<p[i]<<" ";cout<<endl;reverse(all(ans));
 	cout<<sz(ans)<<endl;
 	for(auto i:ans)cout<<i<<endl;
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