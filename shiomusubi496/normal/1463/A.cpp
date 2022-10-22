#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;cin>>Q;
  while(Q--){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--,c--;
    int n=a+b+c,k=n/9;
    if(n%9!=6)goto home;
    if(k>a||k>b||k>c)goto home;
    puts("YES");
    continue;
    home:;
    puts("NO");
  }
}