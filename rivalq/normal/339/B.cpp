#include<bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
   ios_base::sync_with_stdio(0);
   long long int n,m;
    cin>>n>>m;
  long long  int c=0,t=0,h=0;
   cin>>t;
   c+=t-1;
   m--;
    fr(i,m){
      cin>>h;
      c+=(h>=t)?h-t:n-t+h;
      t=h;
    }
    cout<<c<<endl;


}