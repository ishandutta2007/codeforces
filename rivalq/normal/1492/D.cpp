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
 		int a,b,k;cin>>a>>b>>k;
 		if(k==0){
 			cout<<"Yes"<<endl;
 			string res(a+b,'0');
 			for(int i=0;i<b;i++)res[i]='1';
 				cout<<res<<endl<<res<<endl;return 0;
 		}
 		if(a==0 || b==1 || k>a+b-2){
 			cout<<"No"<<endl;
 			return 0;
 		}
 		// k>=1 and k<=a+b-2
 		cout<<"Yes"<<endl;
 		string s(a+b,'0');s[0]='1';s[a+b-1-k]='1';
 		string t(a+b,'0');t[0]='1';t[a+b-1]='1';
 		b-=2;
 		for(int i=1;i<a+b,b>0;i++){
 			if(s[i]=='0' and t[i]=='0'){
 				b--;
 				s[i]=t[i]='1';
 			}
 		}
 		cout<<s<<endl<<t<<endl;return 0;
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