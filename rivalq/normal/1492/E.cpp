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
 		int n,m;cin>>n>>m;
 		vector<vector<int>>a(n+1,vector<int>(m+1));
 		rep(i,1,n+1){
 			rep(j,1,m+1){
 				cin>>a[i][j];
 			}
 		}
 		function<void(int,vector<int>&)>solve1=[&](int k,vector<int>&ans){
 			if(k>n){
 				cout<<"Yes"<<endl;
 				for(int i=1;i<=m;i++){
 					if(ans[i]==0)ans[i]=1;
 					cout<<ans[i]<<" ";
 				}	
 				cout<<endl;
 				exit(0);
 			}
 			vector<int>t;
 			int cnt=0;
 			for(int i=1;i<=m;i++){
 				if(ans[i]==0)t.push_back(i);
 				else cnt+=(ans[i]!=a[k][i]);
 			}
 			if(cnt>2)return;
 			int x=sz(t);
 			if(cnt+x<=2){
 				solve1(k+1,ans);
 				return;
 			}
 			for(int i=0;i<(1<<x);i++){
 				int cnt_t=cnt;
 				for(int j=0;j<x;j++){
 					if((1<<j)&i){
 						cnt_t++;
 					}
 					else{
 						ans[t[j]] = a[k][t[j]];
 					}
 				}
 				if(cnt_t==2)solve1(k+1,ans);
 				for(int j=0;j<x;j++)ans[t[j]]=0;
 			}
 		};
 		auto solve2=[&](int k){
 			vector<int>t;
 			for(int i=1;i<=m;i++){
 				if(a[1][i]!=a[k][i])t.push_back(i);
 			}

 			for(auto choice1:t){
 				for(auto choice2:t){
 					if(choice1==choice2)continue;
 					vector<int>ans=a[1];
 					ans[choice1]=0;
 					ans[choice2]=0;
 					solve1(1,ans);
 				}
 				
 			}
 			for(auto choice1:t){
 				for(auto choice2:t){
 					if(choice1==choice2)continue;
 					vector<int>ans=a[k];
 					ans[choice1]=0;
 					ans[choice2]=0;
 					solve1(1,ans);
 				}
 				
 			}
 		};
 		for(int i=2;i<=n;i++){
 			int cnt=0;
 			rep(j,1,m+1){
 				if(a[1][j]!=a[i][j])cnt++;
 			}
 			if(cnt<=2)continue;
 			if(cnt>4){
 				cout<<"No"<<endl;return 0;
 			}
 			solve2(i);
 			cout<<"No"<<endl;return 0;
 		}
 		cout<<"Yes"<<endl;
 		for(int i=1;i<=m;i++)cout<<a[1][i]<<" ";cout<<endl;
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