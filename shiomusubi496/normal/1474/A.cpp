#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int n;string s;cin>>n>>s;
    string t(n,'0'),u(n,'0');
    for(int i=0;i<n;i++){
      if(s[i]=='1'){
        if(i&&u[i-1]=='2'){
          t[i]='0',u[i]='1';
        }else{
          t[i]='1',u[i]='2';
        }
      }else{
        if(i&&u[i-1]=='1'){
          t[i]='0',u[i]='0';
        }else{
          t[i]='1',u[i]='1';
        }
      }
    }
    cout<<t<<endl;
  }
}