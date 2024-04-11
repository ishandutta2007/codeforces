//https://codeforces.com/contest/1156/problem/E
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=300000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int lgreat[N],rgreat[N];
void compute(int a[],int b[],int n,int k){
    stack<pii>st;
    st.push({a[1],1});
    for(int i=2;i<=n;i++){
       if(st.empty()){
           st.push({a[i],i});
           continue;
       } 
       while(!st.empty() && st.top().x<a[i]){
           b[st.top().x]=i;
           st.pop();
       }
       st.push({a[i],i});
    }
    while(!st.empty()){
        b[st.top().x]=n+1;
        st.pop();
    }
}
int solve(){
 int n;cin>>n;           
 int a[n+1];rep3(n)cin>>a[i+1];
 int ra[n+1];rep(i,1,n+1)ra[i]=a[n-i+1];
 compute(a,rgreat,n,n+1);
 compute(ra,lgreat,n,0);
 int invp[n+1];rep(i,1,n+1)invp[a[i]]=i;
 ll ans=0;
 for(int i=1;i<=n;i++){
     int l=n-lgreat[a[i]]+2;
     int r=rgreat[a[i]]-1;
     int l1=i-l+1;
     int l2=r-i+1;
     if(l1<=l2){
         for(int j=l;j<i;j++){
             int val=a[i]-a[j];
             if(val>0 && val<=n && invp[val]>i && invp[val]<=r)ans++;
         }
     }
     else{
         for(int j=i+1;j<=r;j++){
             int val=a[i]-a[j];
             if(val>0 && val<=n && invp[val]<i && invp[val]>=l)ans++;
         }
     }
 }
 cout<<ans<<endl;
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