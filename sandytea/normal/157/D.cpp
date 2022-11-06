//program 157D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int X[100000],CountYes[100000],CountNo[100000];
bool Type[100000],Flag[100000];

int main()
{
  int N,M;cin>>N>>M;
  int Count=0;
  memset(CountYes,0,sizeof(CountYes));
  memset(CountNo,0,sizeof(CountNo));
  for(int i=0;i<N;i++)
    {
      int T;cin>>T;
      Type[i]=(T>0);X[i]=abs(T)-1;
      if(Type[i])
        CountYes[X[i]]++;
      else
        {Count++;CountNo[X[i]]++;}
    }
  for(int i=0;i<N;i++)Flag[i]=(CountYes[i]+Count-CountNo[i]==M);
  int Only=-2;
  for(int i=0;i<N;i++)if(Flag[i])Only=(Only==-2)?i:-1;
  for(int i=0;i<N;i++)
    {
      int Ans=0;
      if(Type[i])
        {
          if(Flag[X[i]])Ans|=1;
          if(X[i]!=Only)Ans|=2;
        }
      else
        {
          if(Flag[X[i]])Ans|=2;
          if(X[i]!=Only)Ans|=1;
        }
      if(Ans==1)cout<<"Truth"<<endl;
      if(Ans==2)cout<<"Lie"<<endl;
      if(Ans==3)cout<<"Not defined"<<endl;
    }
  return 0;
}