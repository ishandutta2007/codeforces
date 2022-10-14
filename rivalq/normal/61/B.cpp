//https://codeforces.com/contest/61/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  int n;cin>>n;
  string arr[n];
  lop(i,n,1){
      cin>>arr[i];
  }
  
 
  char ja[3]={'-','_',';'};
  lop(i,3,1){
    s1.erase (remove(s1.begin(), s1.end(), ja[i]), s1.end());}
  lop(i,3,1){
    s2.erase (remove(s2.begin(), s2.end(), ja[i]), s2.end());}  
  lop(i,3,1){
    s3.erase (remove(s3.begin(), s3.end(), ja[i]), s3.end());}
  for(int j=0;j<n;j++){ 
    lop(i,3,1){
    arr[j].erase (remove(arr[j].begin(), arr[j].end(), ja[i]), arr[j].end());}
    transform(arr[j].begin(), arr[j].end(), arr[j].begin(), ::tolower); 

  }
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower); 
  transform(s3.begin(), s3.end(), s3.begin(), ::tolower); 
  string t1=s1+s2+s3;
  string t2=s1+s3+s2;
  string t3=s2+s1+s3;
  string t4=s2+s3+s1;
  string t5=s3+s2+s1;
  string t6=s3+s1+s2;
  for(int i=0;i<n;i++){
     // cout<<arr[i]<<endl;
      if(arr[i]==t1||arr[i]==t2||arr[i]==t3||arr[i]==t4||arr[i]==t5||arr[i]==t6){
          cout<<"ACC"<<endl;
      }
      else cout<<"WA"<<endl;
  }


}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}