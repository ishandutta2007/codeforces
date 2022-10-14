#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int i=0;
  vector<string> v(0);
  string t="";
  while(s[i]!='\0'){
      if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
          if(t.length()!=0){
           v.push_back(t);
          t="";
         
          }
          i=i+3;
          
      }
      else{
          t=t+s[i];
          i++;
      }
  }
  v.push_back(t);
  int n=v.size();
  for(int i=0;i<n;i++){
      cout<<v[i]<<" ";
  }
}