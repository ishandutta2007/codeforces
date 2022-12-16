#include <bits/stdc++.h>
using namespace std;
long long  a, c,d,e;
char b[50010101],f;
int main()
{
 ios::sync_with_stdio(0);
 cin.tie(0),cout.tie(0);
 cin>>a;
 cin>>b;
 if(a==1){
  cout<<"Yes";
  return 0;
 }
 sort(b,b+a);
 f=b[0];
 for(int i=0;i<a;i++){
  if(f!=b[i]){
   c=1;
   f=b[i];
  }else {
   c++;
  }
  if(c>=2){
   cout<<"Yes";
   return 0;
  }
 }
 cout<<"No";
 return 0; 
}