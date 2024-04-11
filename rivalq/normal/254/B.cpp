//https://codeforces.com/contest/254/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
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
#define mod 1000000007
using namespace std;
struct date{
    int day;
    int month;
    int year;
   
};
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int solve(){
  int n;
  cin>>n;
  int arr[n][4];
  lop(i,n,1){
      cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
  }
 map<string,int> mp;
  lop(i,n,1){
      int mi=arr[i][0];
      int di=arr[i][1];
      int p=arr[i][2];
      int ti=arr[i][3];
      int yr=2013;
      if(di==1){
          if(mi==1){
              di=31,mi=12,yr=2012;
          }
          else {
              mi--;di=days[mi];
          }
      }
      else di--;
      struct  date td;
      td.day=di;
      td.month=mi;
      td.year=yr;
      while(ti--){
          string t="";
           if((td.day/10)==0)t=t+"0";
           t=t+to_string(td.day)+"-";
           if(td.month/10==0)t+="0";
           t+=to_string(td.month)+"-"+to_string(td.year);
           //cout<<t<<endl;
           mp[t]+=p;
          if(td.day==1){
              if(td.month==1)td.day=31,td.month=12,td.year=2012;
              else{
                  td.month--;td.day=days[td.month];
              }
          }
          else{
                  td.day--;
          }
      }
  }
 int ma=0;
 for(auto i:mp){
     //cout<<i.first<<" "<<i.second<<endl;
     ma=max(ma,i.second);
 }
 cout<<ma<<endl;
 mp.clear();

}
int main(){
    IOS;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}