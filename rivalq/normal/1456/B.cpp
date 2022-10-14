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
	auto msb = [&] (int x){
 		for(int i=29;i>=0;i--){
 			if((1<<i)&x)return i;
 		}
 	};
 	int n;cin>>n;
 	vector<int>a(n+1);
 	set<int>s;
 	rep(i,1,n+1){
 		cin>>a[i];
 		s.insert(msb(a[i]));
 	}
 	if(sz(s)==n){
 		cout<<-1<<endl;return 0;
 	}
 	if(n==2){
 		cout<<-1<<endl;return 0;
 	}
 	if(n==3){
 		if((a[1]^a[2])>a[3]){
 			cout<<1<<endl;
 		}
 		else if(a[1]>(a[2]^a[3])){
 			cout<<1<<endl;
 		}
 		else{
 			cout<<-1<<endl;
 		}
 		return 0;
 	}
 	rep(i,1,n){
 		int v = a[i]^a[i+1];
 		if(i+2<=n && v>a[i+2]){
 			cout<<1<<endl;return 0;
 		}
 		if(i>1 && v<a[i-1]){
 			cout<<1<<endl;return 0;
 		}
 	}
 	// n<=60
 	int ans = hell;
 	rep(i,1,n){
 		int v = 0;
 		for(int j=i+1;j<=n;j++){
 			int v2 = 0;
 			v^=a[j];
 			for(int k=i;k>0;k--){
 				v2^=a[k];
 				if(v2>v){
 					mins(ans,j-i-1+(i-k));
 				}
 			}
 		}
 	}
 	if(ans==hell)cout<<-1<<endl;
 	else cout<<ans<<endl;
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