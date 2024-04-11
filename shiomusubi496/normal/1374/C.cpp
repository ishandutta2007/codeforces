#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
    int n;string s;
    cin>>n>>s;
    int sum=0,right=0;
    for(int i=0;i<n;i++){
      if(s[i]=='(')sum++;
      else if(sum==0)right++;
      else sum--;
    }
    cout<<right<<endl;
  }
}