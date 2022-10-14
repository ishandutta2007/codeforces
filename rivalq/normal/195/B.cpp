//https://codeforces.com/contest/195/problem/B
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
  int n,m;
  cin>>n>>m;
  if(m&1){
    int mid=(m+1)/2;
    int i=1;
    cout<<mid<<endl;
    int q=0;
    n--;
    while(n>0){
      if(mid-i>0){
      if(q==0){cout<<mid-i<<endl,q=1,n--;if(i==0)i++,q=0;}
      else cout<<mid+i<<endl,q=0,i++,n--;
      }
      else i=0;
    }
  }
  else{
    int mid1=m/2;
    int mid2=m/2;
    int q=0;
    while(n>0){
      if(mid1<=0){
        mid1=m/2,mid2=m/2+1,n--;
        cout<<mid1<<endl;
        q=1;
      }
      else{
        if(q==0){
          cout<<mid1<<endl;
          mid2++;
          n--;q=1;
        }
        else{
          cout<<mid2<<endl;
          n--;q=0;mid1--;
        }
      }
    }
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