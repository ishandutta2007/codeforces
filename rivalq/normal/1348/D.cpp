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
 int n;cin>>n;
 int ans=0;
 for(int j=30;j>=0;j--){
 	int k=(1LL<<j);
 	if(k&n){
 		ans=j;break;
 	}
 }
 cout<<ans<<endl;
 vector<int>v(ans);
 v[0]=0;
 int f=1;
 for(int i=1;i<ans;i++){
     v[i]=f;
     f=f*2;    
 }
 if(n==(1<<ans)){
 	for(auto i:v)cout<<i<<" ";cout<<endl;
 	return 0;	
 }
 int val=(n-(1<<ans));
 int l=1;
 for(int i=0;i<ans;i++){
 	int diff=l;
 	if(val>=diff){
 		v[i]=l;
 		val-=diff;
 		if(i<ans-1)v[i+1]=0;
 	}
 	else{
 		v[i]=val;
 		if(i<ans-1)v[i+1]=l-val;
 		break;
 	}
 	l=l*2;
 }
 for_each(all(v),[](int x){cout<<x<<" ";});
 cout<<endl;
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