//program 137A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int Ans=0,Sum=0;
  char Last=' ';
  for(int i=0;i<S.size();i++)
    if(S[i]=='C'||S[i]=='P')
      if(S[i]==Last)
        Sum++;
      else
        {
          if(Sum)Ans+=(Sum-1)/5+1;
          Last=S[i];Sum=1;
        }
  Ans+=(Sum-1)/5+1;
  cout<<Ans<<endl;
  return 0;
}