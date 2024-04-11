//program 131A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int N=S.size();
  bool Flag=true;
  for(int i=1;i<N;i++)if(S[i]>='a')Flag=false;
  if(Flag)
    for(int i=0;i<N;i++)
      if(S[i]>='a')S[i]-=32;else S[i]+=32;
  cout<<S<<endl;
  return 0;
}