//https://codeforces.com/contest/1234/problem/E
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
#define mem1(a)        memset(a,-1,sizeof(a))
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
    //i++;
    while(i){
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
void upbit(ll BIT[],int i,int n,ll val){
    //i++;
    while(i<=n){
        BIT[i]+=val;
        i+=i&(-i);
    }
}
int solve(){
 int n,m;cin>>n>>m;           
 ll arr[m];rep3(m)cin>>arr[i];
 ll sum=0;
 for(int i=0;i<m-1;i++)sum+=abs(arr[i]-arr[i+1]);
 map<ll,map<ll,ll>>mp;
 vector<pii> v;
 for(int i=0;i<m;i++){
     if(i!=0)mp[arr[i]][arr[i-1]]++;
     if(i!=m-1)mp[arr[i]][arr[i+1]]++;
 }
 for(int i=0;i<m-1;i++){
     v.pb({arr[i],arr[i+1]});
     v.pb({arr[i+1],arr[i]});
 }
 int szi=sz(v);
 sort(all(v));
 ll bit[n+1]={0};
 int j=0;
 cout<<sum<<" ";
 for(int i=2;i<=n;i++){
     ll s1=0;
     for(auto j:mp[i]){
         if(j.x<i){
             s1=s1+j.y*(i-2*(i-j.x));
         }
         else if(j.x>i){
             s1=s1+j.y*(i-1);
         }
     }
     while(j<szi && v[j].x<i){
        upbit(bit,v[j].y,n,-1);
        j++;         
     }
     cout<<s1+sum+get(bit,n)-get(bit,i)<<" ";
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