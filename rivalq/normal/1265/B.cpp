//https://codeforces.com/contest/1265/problem/B
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
  int n;
  cin>>n;
  vector<pair<int,int>> v(n);
  lop(i,n,1){cin>>v[i].first;v[i].second=i;}
  sort(all(v));
  string s="1";
  int ma=v[0].second,mi=v[0].second;
  for(int i=2;i<=n;i++){
     ma=max(v[i-1].second,ma);
         mi=min(v[i-1].second,mi);
         if(ma-mi<i){
            s+="1";
         }
         else s+="0";
  }
  cout<<s<<endl;


  
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