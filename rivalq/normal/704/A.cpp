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
int solve(){
  int n,q;cin>>n>>q;
  int arr[q+1]={0};
  int dp=1;
  int s=0;
  queue<int> v[n+1];
  queue<int> qu;
  int no=1;
  int mp[q+1];
  for(int i=1;i<=q;i++){
      int t=1;
      cin>>t;
      if(t==1){
        s++;
        int x;cin>>x;
        v[x].push(no);
        mp[no]=x;
        qu.push(no);
        no++;
      }
      if(t==2){
          int x;cin>>x;
          while(!v[x].empty()){
              int k=v[x].front();
              arr[k]=1;
              v[x].pop();
              s--;
          }
      }
      if(t==3){
          int x;cin>>x;
          while(!qu.empty()){
           int ve=qu.front();
           if(ve>x)break;
           if(arr[ve]==0){
               arr[ve]=1;
               s--;
               v[mp[ve]].pop();
           }
           qu.pop();
          }      
      }
      cout<<s<<endl;
      /**cout<<"--------------"<<endl;
      for(int j=1;j<=n;j++){
          if(v[j].size()==0)continue;cout<<j<<" ";
          for(auto k:v[j])cout<<k<<" ";cout<<endl;
      }
      cout<<"--------------"<<endl;**/
      //for(int j=1;j<=i;j++)cout<<arr[j]<<" ";cout<<endl;

  }
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