#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q; cin>>Q;
  while(Q--){
    int a; cin>>a;
    int b=100-a;
    int c=gcd(a,b);
    a/=c; b/=c;
    cout<<a+b<<endl;
  }
}