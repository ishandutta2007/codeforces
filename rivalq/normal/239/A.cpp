#include<bits/stdc++.h>
using namespace std;
int main(){
  long long  int y,k,n,x=1,c=1;
    cin>>y>>k>>n;
    x= k-y%k;
    if((x+y)>n) c=0;
    if(c==0){cout<<-1<<endl;return 0;}
    cout<<x<<" ";
    x=x+k;
    for(x;x<=n-y;x+=k) cout<<x<<" ";
    cout<<endl;
}