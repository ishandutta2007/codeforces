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
int p[1000005];
vector<int>v;
void sieve(int isprime[],int n){
   rep(i,1,n+1)isprime[i]=1;
   for(int p=2;p*p<=n;p++){
       if(isprime[p]==1){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}
bool isPrime(ll N){
	if(N<2)return false;
	if(N<4)return true;
	if((N&1)==0)return false;
	if(N%3==0)return false;
	ll curr=5,s=sqrt(N);
	while(curr<=s){
		if(N%curr==0)return false;
		curr+=2;
		if(N%curr==0)return false;
		curr+=4;
	}
	return true;
}
int solve(){
 int n;cin>>n;
 if(isPrime(n)){
 	cout<<1<<"\n"<<n<<endl;return 0;
 }
 if(isPrime(n-2)){
 	cout<<2<<"\n"<<2<<" "<<n-2<<endl;
 	return 0; 
 }
 n-=3;
 cout<<3<<"\n";
 for(auto i:v){
 	 if(isPrime(n-i)){
 	 	cout<<3<<" "<<i<<" "<<n-i<<endl;
 	 	return 0;
 	 }
 }
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve(p,1000000);
    for(int i=2;i<=1000000;i++){
    	if(p[i])v.pb(i);
    }
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}