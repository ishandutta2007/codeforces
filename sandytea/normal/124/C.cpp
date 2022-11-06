//program 124C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Parent[1001];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

int main()
{
  string S;cin>>S;int N=S.size();
  bool Flag[1001];memset(Flag,0,sizeof(Flag));
  for(int i=1;i<=N;i++)Parent[i]=i;
  for(int i=2;i<=N;i++)
    if(!Flag[i])
      for(int j=2;i*j<=N;j++)
        {
          Flag[i*j]=true;
          if(Root(i)!=Root(i*j))
            Parent[Root(i)]=Root(i*j);
        }
  int Count[1001];memset(Count,0,sizeof(Count));
  for(int i=1;i<=N;i++)Count[Root(i)]++;
  int Letter[26];memset(Letter,0,sizeof(Letter));
  for(int i=0;i<N;i++)Letter[S[i]-97]++;
  bool Ans=true;char T[1000];
  for(int i=1;Ans&&i<=N;i++)
    if(Count[i]>1)
      {
        int Found=-1;
        for(int j=0;Found==-1&&j<26;j++)
          if(Letter[j]>=Count[i])
            {Found=j;Letter[j]-=Count[i];Count[i]=0;}
        if(Found==-1)
          Ans=false;
        else
          for(int j=1;j<=N;j++)
            if(Root(j)==i)T[j-1]=Found+97;
      }
  for(int i=1;Ans&&i<=N;i++)
    if(Count[i])
      {
        int Found=-1;
        for(int j=0;Found==-1&&j<26;j++)
          if(Letter[j]>=Count[i])
            {Found=j;Letter[j]-=Count[i];}
        if(Found==-1)
          Ans=false;
        else
          for(int j=1;j<=N;j++)
            if(Root(j)==i)T[j-1]=Found+97;
      }
  if(!Ans)
    cout<<"NO"<<endl;
  else
    {
      cout<<"YES"<<endl;
      for(int i=0;i<N;i++)putchar(T[i]);
      putchar('\n');
    }
  return 0;
}