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
 	int l=ceil(n/2.0);
 	int y=n-l;
 	vector<int>a(l+1,0);
 	vector<int>p(l+1,0);
 	vector<int>m(l+1,1e18);
 	int s=0;
 	rep(i,1,l+1)cin>>a[i],s+=a[i];
 	int x;cin>>x;
 	s+=y*x;
 	if(s>0){
 		cout<<n<<endl;return 0;
 	}
 	if(x>0){
 		cout<<-1<<endl;return 0;
 	}
 	int c=1;
 	for(int i=l;i>0;i--){
           p[c]=p[c-1]+a[i];
           m[c]=p[c]-(c)*x;
           c++; 
 	} 
 	for(int i=l-1;i>0;i--){
 		mins(m[i],m[i+1]);
 	}
 	for(int i=1;i<=l;i++){
 		int val=m[i]+(y+i)*x;
 		if(val>0){
 			cout<<y+i<<endl;return 0;
 		}
 	}
 	cout<<-1<<endl;
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