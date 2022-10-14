//https://codeforces.com/contest/1303/problem/C
#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;

int solve(){
 set<int>g[27];
 int visit[27]={0};
 string s;cin>>s;
 int n=s.length();
 if(n==1){
     cout<<"YES"<<endl;
     cout<<"abcdefghijklmnopqrstuvwxyz\n";
     ret;
  }
 for(int i=0;i<n-1;i++){
  g[s[i]-96].insert(s[i+1]-96);
  g[s[i+1]-96].insert(s[i]-96);
 }
 int cnt=0;
 for(int i=1;i<=26;i++){
     if(g[i].size()>2){
         cout<<"NO"<<endl;
         ret;
     }
     if(g[i].size()==1)cnt++;
 }
 if(cnt!=2){
     cout<<"NO"<<endl;
     ret;
 }
 cout<<"YES"<<endl;
 for(int i=1;i<=26;i++){
    if(!visit[i] && g[i].size()==1){
        queue<int>st;
        st.push(i);
        visit[i]=1;
        while(!st.empty()){
            int v=st.front();
            char c=v+96;cout<<c;
            visit[v]=1;
            st.pop();
            for(auto i:g[v]){
                if(!visit[i]){
                    st.push(i);
                }
            }
        }
    }
    else if(!visit[i]&&g[i].size()==0){
        char c=i+96;
        cout<<c;
    }
 }
 cout<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}