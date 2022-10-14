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

// sc = A -B
int solve(){
 	int n;cin>>n;
 	multiset<int>s1,s2;
 	rep(i,1,n+1){
 		int t;cin>>t;
 		if(t&1)s1.insert(t);
 		else s2.insert(t);
 	}
 	int sc=0;
 	bool f=1;
 	while(!s1.empty() || !s2.empty()){
 		 int mx_odd=0,mx_even=0;
 		 if(!s1.empty()){
 		 	mx_odd=*s1.rbegin();
 		 }
 		 if(!s2.empty()){
 		 	mx_even=*s2.rbegin();
 		 }
 		 if(mx_odd>mx_even){
 		 	s1.erase(s1.find(mx_odd));
 		 	if(f==0)sc-=mx_odd;
 		 }
 		 else{
 		 	s2.erase(s2.find(mx_even));
 		 	if(f==1)sc+=mx_even;
 		 }
 		 f^=1;
 	}
 	if(sc>0){
 		cout<<"Alice"<<endl;
 	}
 	else if(sc==0){
 		cout<<"Tie"<<endl;
 	}
 	else{
 		cout<<"Bob"<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}