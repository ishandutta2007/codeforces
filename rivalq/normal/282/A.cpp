#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x=0;
  for(int i=0;i<n;i++){
      string t;
      cin>>t;
      if(t[1]=='-')
      x--;
      else
      {
          x++;
      }
      
  }
cout<<x;

}