//program 123D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  int Link,X;
};

int N;
string S;
int Count[200000],Rank[200000],SA[200000],X[200000],Y[200000],T[200000],Height[200000];
int Parent[100000],Size[100000];
DataType Data[100000];

bool Cmp(DataType A,DataType B)
{
  return A.X>B.X;
}

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

void Calc_SA()
{
  int Total=0;
  memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)Count[S[i]]++;
  for(int i=1;i<128;i++)if(Count[i])Count[i]=++Total;
  for(int i=0;i<N;i++)Rank[i]=Count[S[i]];
  int Step=1;
  while(Step<N&&Total<N)
    {
      for(int i=0;i<N;i++)X[i]=Rank[i];
      for(int i=0,j=Step;i<N;i++,j++)Y[i]=(j<N)?(Rank[j]+1):1;
      memset(Count,0,sizeof(Count));
      for(int i=0;i<N;i++)Count[Y[i]]++;
      for(int i=1;i<=N;i++)Count[i]+=Count[i-1];
      for(int i=0;i<N;i++)T[Count[Y[i]-1]++]=i;
      memset(Count,0,sizeof(Count));
      for(int i=0;i<N;i++)Count[X[i]]++;
      for(int i=1;i<=N;i++)Count[i]+=Count[i-1];
      for(int i=0;i<N;i++)SA[++Count[X[T[i]]-1]]=T[i];
      Total=0;
      for(int i=1;i<=N;i++)
        if(i>1&&X[SA[i]]==X[SA[i-1]]&&Y[SA[i]]==Y[SA[i-1]])
          Rank[SA[i]]=Total;
        else
          Rank[SA[i]]=++Total;
      Step*=2;
    }
  for(int i=0;i<N;i++)SA[Rank[i]]=i;
}

void Calc_Height()
{
  int P=0;
  for(int i=0;i<N;i++)
    {
      if(P)P--;
      if(Rank[i]>1)
        {
          int j=SA[Rank[i]-1];
          while(i+P<N&&j+P<N&&S[i+P]==S[j+P])P++;
        }
      Height[Rank[i]]=P;
    }
}

int main()
{
  cin>>S;N=S.size();
  Calc_SA();Calc_Height();
  for(int i=0;i<N-1;i++){Data[i].Link=i;Data[i].X=Height[i+2];}
  sort(Data,Data+N-1,Cmp);
  long long Ans=(long long)N*(N+1)/2+1,Sum=1;
  for(int i=0;i<N;i++)Parent[i]=i;
  for(int i=0;i<N;i++)Size[i]=1;
  for(int i=N-1,j=0;i>=1;i--)
    {
      while(j<N-1&&Data[j].X==i)
        {
          int P=Root(Data[j].Link),Q=Root(Data[j].Link+1);
          Parent[P]=Q;Sum+=2*Size[P]*Size[Q];Size[Q]+=Size[P];j++;
        }
      Sum++;Ans+=Sum;
    }
  cout<<Ans/2<<endl;
  return 0;
}