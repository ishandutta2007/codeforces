//https://codeforces.com/contest/1102/problem/D
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
int solve(){
  int n;cin>>n;          
  string s;cin>>s;
  reverse(all(s));
  int dzero=-n/3,done=-n/3,dtwo=-n/3;
  rep3(n){
      if(s[i]=='0')dzero++;
      else if(s[i]=='1')done++;
      else dtwo++;
  }          
  int i=0;
  while(dtwo<0){
    if(s[i]!='2'){
        if(s[i]=='1'){
            if(done<=0){
                goto x;
            }
            done--;
            s[i]='2';dtwo++;
        }
        else{
            if(dzero<=0){
                goto x;
            }
            dzero--;
            s[i]='2';dtwo++;
        }
    }
    x:
    i++;
  }
   i=n-1;
   while(dzero<0){
    if(s[i]!='0'){
        if(s[i]=='1'){
            if(done<=0){
               goto xx;
            }
            done--;
            s[i]='0';dzero++;
        }
        else{
            if(dtwo<=0){
                goto xx;
            }
            dzero++;
            s[i]='0';dtwo--;
        }
    }
    xx:
    i--;
  }
  for(int i=n-1;i>=0;i--){
      if(dtwo<=0 || done>=0)break;
      if(s[i]=='2'){
           s[i]='1';
           done++;
           dtwo--;
      }
  }
  for(int i=0;i<n;i++){
      if(done>=0)break;
      if(s[i]=='0'){
           s[i]='1';
           done++;
           dzero--;
      }
  }
  reverse(all(s));
  cout<<s<<endl;
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