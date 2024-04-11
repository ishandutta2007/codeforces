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
int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}


int solve(){
 	int n,m;cin>>n;
        map<int,int>mp;
        vector<int>a(n+1),b(n+1);
        int cnt=0;
 	rep(i,1,n+1){
 		int t;cin>>t;
 		mp[t]++;
 		a[i]=t;
 	}
 	rep(i,1,n+1){
 		cin>>b[i];
 		mp[b[i]]++;
 		if(a[i]==b[i])cnt++;
 	}
 	cin>>m;
 	vector<int>f(2*n+1,1);
 	rep(i,2,2*n+1)f[i]=f[i-1]*i%m;
 	int ans=1;
 	int v=0;
 	for(auto i:mp){
 		for(int j=1;j<=i.y;j++){
 			int val=j;
 			while(val%2==0)val/=2,v++;
 			ans=ans*val%m;
 		}
 	}
 	cout<<ans*expo(2,v-cnt,m)%m<<endl;
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