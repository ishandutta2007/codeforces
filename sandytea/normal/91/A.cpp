//program 91A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S,T;cin>>S>>T;
  int N=S.size(),M=T.size(),Ans=0,P=0;
  for(int i=0;i<N;i++)S[i]-=97;
  for(int i=0;i<M;i++)T[i]-=97;
  int Last[26],Next[10000][26];
  for(int i=0;i<26;i++)Last[i]=N;
  for(int i=N-1;i>=0;i--)
    {
      Last[S[i]]=i;
      for(int j=0;j<26;j++)
        Next[i][j]=Last[j];
    }
  while(P<M)
    {
      int Last=P,Q=0;Ans++;
      while(P<M&&Q<N&&Next[Q][T[P]]<N)Q=Next[Q][T[P++]]+1;
      if(P==Last){Ans=-1;break;}
    }
  cout<<Ans<<endl;
  return 0;
}