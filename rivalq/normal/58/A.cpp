#include<bits/stdc++.h>
using namespace std;
int main(){

  string s;
  cin>>s;
  int h=0,e=0,l=0,o=0;
  int n= s.length();
  for (int i = 0; i < n; i++)
  {
   if(s[i]=='h'){
       h=1;
   }
   if(s[i]=='e'&& h==1){
       e=1;
   }
   if(s[i]=='l'&& e==1){
       l++;
   }
   if(s[i]=='o'&&l==2){
       o=1;
       break;
   }

  }
  if((l+h+e+o)>=5)
  cout<<"YES"<<endl;
  else
  {
      cout<<"NO"<<endl;
  }
  


}