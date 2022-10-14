//https://codeforces.com/contest/242/problem/D
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
set<int> s;
vector<int> g[N+10];
int c[N+10];
int a[N+10];
void dfs(int n){
    if(pres(s,n)){
        cout<<-1<<endl;
        exit(0);
    }
    s.insert(n);
    c[n]++;
    for(auto i:g[n]){
        c[i]++;
        if(c[i]==a[i]){
            dfs(i);
        }
    }
}
int solve(){
 int n,m;cin>>n>>m;           
 rep3(m){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 }
 rep3(n)cin>>a[i+1];
 for(int i=1;i<=n;i++){
    if(a[i]==c[i]){
        dfs(i);
    }
 }
 cout<<sz(s)<<endl;
 for(auto i:s)cout<<i<<" ";           
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