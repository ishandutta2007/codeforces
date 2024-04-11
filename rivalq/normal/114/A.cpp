#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,l,i=1;
    cin>>k>>l;
    while(1){
      if(pow(k,i)==l) {cout<<"YES"<<"\n"<<i-1<<endl; return 0;}
      else if(pow(k,i)>l){cout<<"NO"<<endl; return 0;}
      else i++;

    }
    cout<<"NO"<<endl;
}