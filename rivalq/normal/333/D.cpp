#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
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
#define long           long long
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int maxn=1001;
bitset<1024>b[maxn];
int a[maxn][maxn];
bool ch(int val,int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[i][j]=0;
	}

	for(int j=1;j<=m;j++){
		vector<int>temp;
		
		for(int i=1;i<=n;i++){
			if(a[i][j]>=val)temp.pb(i);
		}
		for(int i=0;i<sz(temp);i++){
			for(int k=i+1;k<sz(temp);k++){
				if(b[temp[i]][temp[k]])return 1;
				b[temp[i]][temp[k]]=1;
			}
		}
	}
	return 0;
}
int solve(){
    int n,m;cin>>n>>m;
    vector<int>z(n*m+1,0);
    for(int i=1;i<=n;i++){
 	   for(int j=1;j<=m;j++)cin>>a[i][j],z[(i-1)*m+j]=a[i][j];
    }
    sort(all(z));
    int lo=1;
    int hi=n*m;
    int ans=z[lo];
    while(lo<=hi){
       int val=(lo+hi)/2;
       if(ch(z[val],n,m))ans=z[val],lo=val+1;
       else hi=val-1; 
    }
    cout<<ans<<endl;
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