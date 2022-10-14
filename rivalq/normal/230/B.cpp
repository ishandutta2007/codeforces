#include<bits/stdc++.h>
using namespace std;
int ip(long long int n){
    if (n==2) return 1;
    if(n%2==0 || n==1) return 0;
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}
long long int isq(long long int n){
    if(n==1||n==0) return n;
 long long int u=n/2,l=1,mid;
  while(l<=u){
    mid=(l+u)/2;
   long long unsigned  int t=mid*mid;
      if(t==n) return mid;
      else if(t>n) {
          u=mid-1;
      }
      else l=mid+1;
  }
  return 0;

}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 long long int n,x;
  cin>>n;
  while(n--){
     cin>>x;
   long long  int t= isq(x);
     if(t){
         if(ip(t)) cout<<"YES\n";
         else cout<<"NO\n";
     }
     else {
         cout<<"NO\n";
     }
  }
  
}