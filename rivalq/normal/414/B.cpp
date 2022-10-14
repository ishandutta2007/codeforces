//https://codeforces.com/problemset/problem/414/B
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) rep1(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998244353
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int countdiv(int n){
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cnt++;
            if(i!=n/i)cnt++;
        }
    }
    return cnt;
}
ll dp[2000+1][2000+1]={0};
int solve(){
  int n,k;cin>>n>>k;
  int d[n+1]={0};
  for(int i=0;i<=n;i++){
      d[i]=countdiv(i);
  }
  for(int i=1;i<=n;i++){
      dp[i][1]=1;
  }
  for(int i=1;i<=n;i++){
      dp[i][2]=d[i];
  }
  for(int i=3;i<=k;i++){
      for(int j=1;j<=n;j++){
            for(int l=j;l<=n;l+=j){
              dp[l][i]=(dp[l][i]+dp[j][i-1])%hell;
            }
      }
  }
  ll sum=0;
  for(int i=1;i<=n;i++)sum=(sum+dp[i][k])%hell;
  cout<<sum<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}