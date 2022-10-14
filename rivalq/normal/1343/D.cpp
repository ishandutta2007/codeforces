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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
int a[200005];
int s[400005];
int solve(){
 int n,k;cin>>n>>k;
 for(int i=1;i<=n;i++)cin>>a[i];
 for(int i=1;i<=2*k;i++)s[i]=0;
 for(int i=1;i<=n/2;i++){
    int k1=a[i];
    int k2=a[n-i+1];
    s[min(k1,k2)+1]--;
    s[k1+k2]--;
    s[k1+k2+1]++;
    s[1]+=2;
    s[k+max(k1,k2)+1]++;
 }
 int mi=n;
 for(int i=1;i<=2*k;i++)s[i]+=s[i-1];
 for(int i=1;i<=2*k;i++){
 	mins(mi,s[i]);
 }	
 cout<<mi<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}