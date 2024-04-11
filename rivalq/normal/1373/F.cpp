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
	vector<int>a(n+1),b(n+1);
	int s1=0,s2=0;
	rep(i,1,n+1){
		cin>>a[i];
	} 
	rep(i,1,n+1){
		cin>>b[i];
	}
	auto f=[&](int x){
		int val=a[1]-b[1]+x;
		if(val>b[n]){
			return 1LL;
		}
		int temp=b[n];
		b[n]=min(b[n],b[n]-val);
		int flag=0;
		for(int i=2;i<=n;i++){
			int val=a[i]-x;
			if(val>b[i]){
				b[n]=temp;
				return flag;
			}
			if(val<0)flag=1;
			x=min(b[i],b[i]-val);
		}
		b[n]=temp;
		return 2LL;
	};
	int l=0,r=b[1];
	while(l<=r){
		int mid=(l+r)/2;
		int x=f(mid);
		if(x==2){
			cout<<"YES"<<endl;return 0;
		}
		else{
			if(x==1)r=mid-1;
			else l=mid+1;
		}
	}
	cout<<"NO"<<endl;return 0;
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