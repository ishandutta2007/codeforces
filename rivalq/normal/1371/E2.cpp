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
 	int n,p;cin>>n>>p;
 	vector<int>a(n+1);
 	rep(i,1,n+1)cin>>a[i];
 	sort(all(a));
 	auto ch=[&](int x){
 		for(int i=1;i<=n;i++){
 			if(x<a[i])return 0;
 			x++;
 		}
 		return 1;
 	};
 	auto calc=[&](int x){
 		int val=1;
 		int cnt=0;
 		int j=1;
 		for(int i=1;i<=n;i++){
 			while(j<=n && a[j]<=x){
 				j++;
 				cnt++;
 			}
 			val=val*cnt%p;
 			x++;cnt--;
 			if(val==0)return 0;
 		}
 		return 1;
 	};
 	int l=1;int r=1e9;
 	int ans=1;
 	while(l<=r){
 		int mid=(l+r)/2;
 		int pt=ch(mid);
 		if(pt)r=mid-1,ans=mid;
 		else l=mid+1;
 	}
 	if(calc(ans)==0){
 		cout<<0<<endl;return 0;
 	}
 	int ans2=1;
 	l=ans;r=1e9;
 	while(l<=r){
 		int mid=(l+r)/2;
 		if(calc(mid))ans2=mid,l=mid+1;
 		else r=mid-1;
 	}
 	cout<<ans2-ans+1<<endl;
 	for(int i=ans;i<=ans2;i++)cout<<i<<" ";cout<<endl;
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