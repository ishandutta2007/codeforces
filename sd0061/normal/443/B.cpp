
 #include <iostream>
#include <string>
int i,k,n,l,c,x,ok;
std::string s;
int main(){ 
 std::cin>>s>>k;
 for(n=s.length();i<n;i++)
  for(c=l+1;i+c*2<=n+k;c++){
   for(ok=1,x=0; x<c && i+c+x<n && ok; x++)
    if(s[i+x]!=s[i+c+x])ok=0;
   if(ok)l=c;
  }
 std::cout<<l*2;
}