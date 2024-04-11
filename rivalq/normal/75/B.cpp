//https://codeforces.com/contest/75/problem/B
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
int solve(){
  string name;int n; 
  cin>>name>>n;
  map<string,int>mp;
  lop(i,n,1){
      string n1,a,t,n2,t2;
      cin>>n1>>a;
      if(a=="posted"||a=="commented")cin>>t>>n2>>t2;
      else cin>>n2>>t2;
      int points= (a=="posted")?15:(a=="commented")?10:5;
     // n1=n1.substr(0,n1.length()-2);
      n2=n2.substr(0,n2.length()-2);
     if(n1!=name && mp.find(n1)==mp.end())mp[n1]=0;
     if(n2!=name && mp.find(n2)==mp.end())mp[n2]=0;
     if(n2==name)
      mp[n1]+=points;
     if(n1==name)
      mp[n2]+=points; 
     
      
  }
  vector<pair<int,string>> v;
  for(auto i:mp){
      v.pb({i.sc,i.fr});
  }
  sort(all(v),greater<pair<int,string>>());
  n=v.size();
  int i=0;
  while(i<n){
      int j=i;
      while(j<n && v[i].fr==v[j].fr){
          j++;
      }
      int start=i,end=j-1;
      while(start<end){
          string t=v[start].sc;
          v[start].sc=v[end].sc;
          v[end].sc=t;start++;end--;
          
      }
      i=j;
  }
  for(int i=0;i<n;i++)cout<<v[i].sc<<endl;
 //int x= ("likes">"posted")?1:0;
 //cout<<x<<endl;
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