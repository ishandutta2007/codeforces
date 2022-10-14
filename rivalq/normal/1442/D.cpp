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


const int N = 3e3+5;

vector<pii>t[4*N];
int n,k;

vector<int>a[N];

int ans=0;

void add_item(int l,int r,pii item,int tl=1,int tr=n,int v=1){
	if(l>tr || tl>r)return;
	if(l<=tl && tr<=r){
		t[v].push_back(item);return;
	}
	int mid=(tl+tr)/2;
	add_item(l,r,item,tl,mid,2*v);
	add_item(l,r,item,mid+1,tr,2*v+1);
}

void dfs(vector<int>dp,int tl=1,int tr=n,int v=1){
	vector<int>new_dp=dp;
	for(auto [value,weight]:t[v]){
		for(int j=k;j>=weight;j--){
			maxs(new_dp[j],new_dp[j-weight]+value);
		}
	}
	if(tl==tr){
		for(int i=0;i<sz(a[tl]);i++){
			if(i>k)break;
			maxs(ans,new_dp[k-i]+a[tl][i]);
		}
		return;
	}else{
		int mid=(tl+tr)/2;
		dfs(new_dp,tl,mid,2*v);
		dfs(new_dp,mid+1,tr,2*v+1);
	}
}



int solve(){
 		cin>>n>>k;
 		rep(i,1,n+1){
 			int t;cin>>t;
 			a[i].resize(t+1);
 			rep(j,1,t+1){
 				cin>>a[i][j];
 				a[i][j]+=a[i][j-1];
 			}
 			if(i-1>0)add_item(1,i-1,{a[i][t],t});
 			if(i+1<=n)add_item(i+1,n,{a[i][t],t});
 		}	
 		vector<int>dp(k+1,0);
 		dfs(dp);
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