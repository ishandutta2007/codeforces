#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
ll BIT[26][100010];
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll get(int j,int i){
    ll sum=0;
    i++;
    while(i>0){
        sum+=BIT[j][i];
        i-=i&(-i);
    }
    return sum;
}
void upbit(int j,int i,int n,ll val){
    i++;
    while(i<=n){
        BIT[j][i]+=val;
        i+=i&(-i);
    }
}
int solve(){
  string s;cin>>s;
  int n=s.length();
  
  for(int i=0;i<26;i++){
      for(int j=0;j<=n;j++)BIT[i][j]=0;
  }
  for(int i=0;i<n;i++){
      upbit(s[i]-97,i,n,1);
  }
  int q;cin>>q;
  lop(i,q,1){
      int t;cin>>t;
      char c;int l,r;
      switch(t){
        case 1:
        cin>>l>>c;
        upbit(s[l-1]-97,l-1,n,-1);
        upbit(c-97,l-1,n,1);
        s[l-1]=c;
        break;
        case 2:
        cin>>l>>r;
        int cnt=0;
        for(int i=0;i<26;i++){
            cnt=(get(i,r-1)-get(i,l-2))?cnt+1:cnt;
        }
        cout<<cnt<<endl;
        break;
      }
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