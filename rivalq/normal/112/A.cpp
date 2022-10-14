#include<bits/stdc++.h>
using namespace std;
int main(){
 string s1;
 string s2;
 cin>>s1>>s2;
 int n=s1.length();
 transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
 transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
 for(int i=0;i<n;i++){
  if(s1[i]>s2[i]){
      cout<<1<<endl;
      return 0;
  }
  if(s1[i]<s2[i]){
      cout<<-1<<endl;
      return 0;
  }


 }
  cout<<0<<endl;
 return 0;
}