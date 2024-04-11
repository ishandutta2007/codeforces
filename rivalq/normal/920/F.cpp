//https://codeforces.com/problemset/problem/920/F
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll get(ll BIT[],int i){
    ll sum=0;
    i++;
    while(i){
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
void upbit(ll BIT[],int i,int n,ll val){
    i++;
    while(i<=n){
        BIT[i]+=val;
        i+=i&(-i);
    }
}
int func(int a){
    int cnt=0;
    for(int i=1;i<=sqrt(a);i++){
        if(a%i==0){
            cnt++;
            if(i!=a/i)cnt++;
        }
    }
    return cnt;
}
int dp[1000001];
int solve(){   
 int n,q;cin>>n>>q;    
 ll bit[n+1]={0};  
 int ma=0;      
 int arr[n];rep3(n){
     cin>>arr[i];
     ma=max(ma,arr[i]);
     upbit(bit,i,n,arr[i]);
 }
 for(int i=1;i<=ma;i++){
     for(int j=i;j<=ma;j+=i){
         dp[j]++;
     }
 }
 map<int,int>mp;
 set<int>s;
 rep3(n){
     mp[i]=arr[i];
     if(mp[i]==2 || mp[i]==1)s.insert(i);
 }
 for(auto i:s)mp.erase(i);
 rep3(q){
     int t;cin>>t;
     if(t==2){
         int l,r;cin>>l>>r;
         l--,r--;
         cout<<get(bit,r)-get(bit,l-1)<<endl;
     }
     else{
         int l,r;cin>>l>>r;
         l--;r--;
         set<int>s;
         auto itr=mp.lower_bound(l);
         for(itr;;itr++){
          if(itr==mp.end())break;   
          if(itr->x>r)break;
          if(dp[itr->y]==-1)dp[itr->y]=func(itr->y);
          int nval=dp[itr->y];
          int diff=nval-arr[itr->x];
          upbit(bit,itr->x,n,diff);
          arr[itr->x]=nval;
          itr->y=nval;
          if(nval<3)s.insert(itr->x);
         }
         for(auto i:s)mp.erase(i);
     }
     //for(auto j:arr)cout<<j<<" ";cout<<endl;
 }           
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}