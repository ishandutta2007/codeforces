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
int a[100005][7]={0};
bool ch(int n,int m,int l,int k){
   if(l==0)return 1;
	 deque<int>s[m];
	 int sum=0;
	 for(int i=0;i<m;i++){
          for(int j=0;j<l;j++){
          	  while(!s[i].empty() && a[j][i]>=a[s[i].back()][i])s[i].pop_back();
          	  s[i].push_back(j);
          }
          assert(!s[i].empty());
          sum+=a[s[i].front()][i];
	 }
	 if(sum<=k)return 1;
	 for(int j=l;j<n;j++){
	 	  sum=0;
	 	  for(int i=0;i<m;i++){
	 		  while(!s[i].empty() && s[i].front()<=j-l)s[i].pop_front();
	 		  while(!s[i].empty() && a[j][i]>=a[s[i].back()][i])s[i].pop_back();
          	s[i].push_back(j);
          	sum+=a[s[i].front()][i];
	 	}
	 	if(sum<=k)return 1;
	}
	return 0;
}
void print(int a[],int m){
	for(int i=0;i<m;i++)cout<<a[i]<<" ";cout<<endl;exit(0);
}
int solve(){
 int n,m,k;cin>>n>>m>>k;
 if(k==0){
   cout<<0<<endl;return 0;
 }
 for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++)cin>>a[i][j];
 }
 int l=0;
 int u=n;
 int ans=0;
  while(l<=u){
 	   int c=(l+u)/2;
 	   if(ch(n,m,c,k))l=c+1,ans=c;
 	   else u=c-1;
  }
 l=ans;
 if(l==0){
 	  for(int i=0;i<m;i++)cout<<0<<" ";cout<<endl;return 0;
 }
 set<pii,greater<pii>>s[m];
 int sum=0;
 int ma[m]={0};
 for(int i=0;i<m;i++){
     for(int j=0;j<l;j++){
          	s[i].insert({a[j][i],j});
      }
      ma[i]=s[i].begin()->x;
      sum+=s[i].begin()->x;
 }
 if(sum<=k)print(ma,m);
 for(int j=1;j+l-1<n;j++){
	 	sum=0;
	 	for(int i=0;i<m;i++){
	 		s[i].erase({a[j-1][i],j-1});
	 		s[i].insert({a[j+l-1][i],j+l-1});
	 		ma[i]=s[i].begin()->x;
	 		sum+=s[i].begin()->x;
	 	}
	 	if(sum<=k)print(ma,m);
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