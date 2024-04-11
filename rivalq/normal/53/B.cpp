//https://codeforces.com/contest/53/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  ll h,w;
  cin>>h>>w;
  ll ph=h,pw=w;
  ll k = log2(w);
  w=pow(2,k);
  if(4*h>5*w){
      h=5*w/4;
  }
  if(4*w>5*h){
    w=5*h/4;
  }
  
 k =log2(ph);
 ph=pow(2,k);
 if(4*ph>5*pw){
      ph=5*pw/4;
  }
  if(4*pw>5*ph){
    pw=5*ph/4;
  }
  if(ph*pw>h*w){
      cout<<ph<<" "<<pw<<endl;
  }
  else cout<<h<<" "<<w<<endl;

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