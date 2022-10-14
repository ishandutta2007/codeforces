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
 	while(1){
 		string s;cin>>s;
 		if(s=="end"){
                       exit(0);
 		}
 		cout<<"? "<<0<<" "<<1<<endl;cout<<flush;
 		char c;cin>>c;
 		if(c=='x'){
 			cout<<"! 1"<<endl;cout<<flush;continue;
 		}
 		int x=1;
 		while(2*x<1e9){
 			int y=x<<1;
 			cout<<"? "<<x<<" "<<y<<endl;cout<<flush;
 			char c;cin>>c;
 			if(c=='x')break;
 			x=y;
 		}
 		int l=x;
 		int r=2*x;
                while(r-l>1){
                	int mid=(l+r)/2;
                	cout<<"? "<<l<<" "<<mid<<endl;cout<<flush;
                	char c;cin>>c;
                	if(c=='x'){
                		r=mid;
                	}
                	else{
                		l=mid;
                	}
                } 
                cout<<"? "<<l<<" "<<r<<endl;cout<<flush;
                cin>>c; 
                int ans;
                if(c=='x')ans=r;
                else ans=l;
                cout<<"! "<<ans<<endl;cout<<flush;
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