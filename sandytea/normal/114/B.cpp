//program 114B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;



int main()
{
  int N,M;cin>>N>>M;
  string Name[16];map<string,int> Number;
  for(int i=0;i<N;i++){cin>>Name[i];Number[Name[i]]=i;}
  int Pair[1000];
  for(int i=0;i<M;i++)
    {
      string S,T;cin>>S>>T;
      Pair[i]=(1<<Number[S])|(1<<Number[T]);
    }
  int Most=0,Ans=0;
  int Count[65536];Count[0]=0;
  for(int i=1;i<(1<<N);i++)
    {
      Count[i]=Count[i^(i&(-i))]+1;
      if(Count[i]>Most)
        {
          bool Flag=true;
          for(int j=0;Flag&&j<M;j++)Flag=((i&Pair[j])!=Pair[j]);
          if(Flag){Most=Count[i];Ans=i;}
        }
    }
  cout<<Most<<endl;
  int T=0;string S[16];for(int i=0;i<N;i++)if(Ans&(1<<i))S[T++]=Name[i];
  sort(S,S+T);
  for(int i=0;i<T;i++)cout<<S[i]<<endl;
  return 0;
}