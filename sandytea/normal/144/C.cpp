//program 144C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S,T;cin>>S>>T;
  int N=S.size(),M=T.size(),Ans=0,Count[26],Sum[26];
  memset(Count,0,sizeof(Count));
  for(int i=0;i<M;i++)Count[T[i]-97]++;
  memset(Sum,0,sizeof(Sum));
  for(int i=0;i<N;i++)
    {
      if(S[i]!='?')Sum[S[i]-97]++;
      if(i>=M&&S[i-M]!='?')Sum[S[i-M]-97]--;
      if(i>=M-1)
        {
          bool Flag=true;
          for(int j=0;j<26;j++)if(Sum[j]>Count[j])Flag=false;
          if(Flag)Ans++;
        }
    }
  cout<<Ans<<endl;
  return 0;
}