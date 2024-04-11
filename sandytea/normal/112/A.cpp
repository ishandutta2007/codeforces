//program 112A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S1,S2;cin>>S1>>S2;
  for(int i=0;i<S1.size();i++)if(S1[i]<='Z')S1[i]+=32;
  for(int i=0;i<S2.size();i++)if(S2[i]<='Z')S2[i]+=32;
  if(S1==S2)cout<<0<<endl;
  if(S1<S2)cout<<-1<<endl;
  if(S1>S2)cout<<1<<endl;
  return 0;
}