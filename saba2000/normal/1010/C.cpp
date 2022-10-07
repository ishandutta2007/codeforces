#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
   int n,k;
   cin>>n>>k;
   for(int i = 0; i < n; i++){
    cin>>a[i], a[i]=__gcd(a[i],k);
    if(i) a[i] = __gcd(a[i],a[i-1]);
   }
   cout<<k / a[n-1]<<endl;
   for(int i = 0; i < k/a[n-1]; i++)
    cout<<i*a[n-1]<<" ";



}