#include<bits/stdc++.h>
using namespace std;
int main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n,x;
    cin>>n>>x;
    cout<<(n==1 || n==2?1:(n+x-3)/x+1)<<endl;
  }
}