//https://codeforces.com/contest/197/problem/B
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
  int n,m,t;
  cin>>n>>m;
  int ao,bo;
  cin>>ao;
  lop(i,n,1)cin>>t;
  cin>>bo;
  lop(i,m,1)cin>>t;
  if(n>m){
      if(ao*bo>0)cout<<"Infinity"<<endl;
      else cout<<"-Infinity"<<endl;
  }
  else if(m>n) cout<<"0/1"<<endl;
  else{
      int aao=abs(ao);
      int abo=abs(bo);
      int q=__gcd(aao,abo);
      aao/=q,abo/=q;
      if(ao*bo<0)cout<<"-";
      cout<<aao<<"/"<<abo<<endl;
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