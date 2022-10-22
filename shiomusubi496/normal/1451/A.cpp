#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n;
    cin>>n;
    if(n==1)puts("0");
    else if(n==2)puts("1");
    else if(n%2==0 || n==3)puts("2");
    else puts("3");
  }
}