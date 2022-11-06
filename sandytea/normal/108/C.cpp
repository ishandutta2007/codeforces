//program 108C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  int N,M;cin>>N>>M;
  int Next[1000],Last[1000],Flow[1000];
  for(int i=0;i<N;i++)Next[i]=-1;
  for(int i=0;i<N;i++)Last[i]=-1;
  while(M--)
    {
      int X,Y,W;cin>>X>>Y>>W;X--;Y--;
      Next[X]=Y;Last[Y]=X;Flow[X]=W;
    }
  int Total=0,Ans_X[1000],Ans_Y[1000],Ans_Flow[1000];
  for(int i=0;i<N;i++)
    if(Last[i]==-1&&Next[i]!=-1)
      {
        Ans_X[Total]=i;Ans_Y[Total]=i;Ans_Flow[Total]=inf;
        while(Next[Ans_Y[Total]]!=-1)
          {
            Ans_Flow[Total]=min(Ans_Flow[Total],Flow[Ans_Y[Total]]);
            Ans_Y[Total]=Next[Ans_Y[Total]];
          }
        Total++;
      }
  cout<<Total<<endl;
  for(int i=0;i<Total;i++)cout<<Ans_X[i]+1<<' '<<Ans_Y[i]+1<<' '<<Ans_Flow[i]<<endl;
  return 0;
}