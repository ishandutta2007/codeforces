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
      int n,k;cin>>n>>k;
      vector<int>a(n+1);
      rep(i,1,n+1)cin>>a[i],a[i]*=-1;
      map<int,int>mp;
      set<pii>s;
      for(int i=1;i<=k;i++){
      	  s.erase({mp[a[i]],a[i]});
      	  mp[a[i]]++;
          s.insert({mp[a[i]],a[i]});
      } 
      if(s.begin()->x==1)cout<<-s.begin()->y<<endl;
      else cout<<"Nothing"<<endl; 
      for(int i=2;i+k-1<=n;i++){
             s.erase({mp[a[i-1]],a[i-1]});
             mp[a[i-1]]--;
             if(mp[a[i-1]]==0){
             	 mp.erase(a[i-1]);
             }
             else{
             	 s.insert({mp[a[i-1]],a[i-1]});
             }
             s.erase({mp[a[i+k-1]],a[i+k-1]});
             mp[a[i+k-1]]++;
             s.insert({mp[a[i+k-1]],a[i+k-1]});
             if(s.begin()->x==1)cout<<-s.begin()->y<<endl;
             else cout<<"Nothing"<<endl; 
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