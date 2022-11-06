//program 135D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int V1[8]={-1,0,0,1,-1,-1,1,1};
const int V2[8]={0,-1,1,0,-1,1,-1,1};

int M,N,Color=0;
bool Map[1000][1000],Flag[1000][1000];
int Cycle[1000][1000];
int X[1000000],Y[1000000],A[1000000],B[1000000];

bool Check(int X,int Y)
{
  int Sum=0;
  if(X>0&&Cycle[X-1][Y]==Color)Sum++;
  if(X+1<M&&Cycle[X+1][Y]==Color)Sum++;
  if(Y>0&&Cycle[X][Y-1]==Color)Sum++;
  if(Y+1<N&&Cycle[X][Y+1]==Color)Sum++;
  return (Sum==2);
}

int BFS(int P,int Q)
{
  int F=0,R=1;
  Flag[P][Q]=true;X[0]=P;Y[0]=Q;
  while(F<R)
    {
      int X0=X[F],Y0=Y[F];F++;
      for(int D=0;D<8;D++)
        {
          int X1=X0+V1[D],Y1=Y0+V2[D];
          if(X1>=0&&X1<M&&Y1>=0&&Y1<N)
            if(!Map[X1][Y1]&&!Flag[X1][Y1])
              {
                Flag[X1][Y1]=true;
                X[R]=X1;Y[R]=Y1;R++;
              }
        }
    }
  int Total=0;Color++;
  for(int i=0;i<R;i++)
    {
      if(X[i]==0||X[i]==M-1||Y[i]==0||Y[i]==N-1)return 0;
      for(int D=0;D<8;D++)
        {
          int X1=X[i]+V1[D],Y1=Y[i]+V2[D];
          if(Map[X1][Y1]&&Cycle[X1][Y1]!=Color)
            {
              Cycle[X1][Y1]=Color;
              A[Total]=X1;B[Total]=Y1;Total++;
            }
        }
    }
  for(int i=0;i<Total;i++)if(!Check(A[i],B[i]))return 0;
  F=0;R=1;X[0]=A[0];Y[0]=B[0];Cycle[X[0]][Y[0]]=Color;
  while(F<R&&R<Total)
    {
      int X0=X[F],Y0=Y[F];F++;
      for(int D=0;D<4;D++)
        {
          int X1=X0+V1[D],Y1=Y0+V2[D];
          if(Cycle[X1][Y1]==Color)
            {
              Cycle[X1][Y1]=Color-1;
              X[R]=X1;Y[R]=Y1;R++;
            }
        }
    }
  if(R<Total)return 0;
  return Total;
}

int main()
{
  cin>>M>>N;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      {
        char c=getchar();
        while(c!='0'&&c!='1')c=getchar();
        Map[i][j]=(c=='1');
      }
  int Ans=0;
  for(int i=0;i+1<M;i++)
    for(int j=0;j+1<N;j++)
      if(Map[i][j]&&Map[i][j+1]&&Map[i+1][j]&&Map[i+1][j+1])
        Ans=4;
  memset(Flag,0,sizeof(Flag));
  memset(Cycle,0,sizeof(Cycle));
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      if(!Map[i][j]&&!Flag[i][j])
        Ans=max(Ans,BFS(i,j));
  cout<<Ans<<endl;
  return 0;
}