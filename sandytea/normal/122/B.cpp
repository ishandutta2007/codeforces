//program 122B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int C4=0,C7=0;
  for(int i=0;i<S.size();i++)
    {
      if(S[i]=='4')C4++;
      if(S[i]=='7')C7++;
    }
  cout<<((C4||C7)?((C4>=C7)?4:7):-1)<<endl;
  return 0;
}