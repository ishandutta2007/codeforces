//program 96A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int Current=-1,Len=0;bool Ans=false;
  for(int i=0;i<S.size();i++)
    {
      if(Current!=S[i]){Current=S[i];Len=0;}
      Len++;if(Len==7)Ans=true;
    }
  cout<<(Ans?"YES":"NO")<<endl;
  return 0;
}