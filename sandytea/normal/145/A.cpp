//program 145A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S,T;cin>>S>>T;
  int Count1=0,Count2=0;
  for(int i=0;i<S.size();i++)
    if(S[i]!=T[i])
      if(S[i]=='4')Count1++;else Count2++;
  cout<<max(Count1,Count2)<<endl;
  return 0;
}