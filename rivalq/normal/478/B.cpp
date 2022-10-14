#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned
int main(){
  llu  int n,m;
    cin>>n>>m;
   llu int ma= n-m+1;
    ma=ma*(ma-1)/2;
   llu int t=n/m;
   llu int mi=n%m*(t*(t+1)/2)+(m-n%m)*(t*(t-1)/2);
    cout<<mi<<" "<<ma<<"\n";

}