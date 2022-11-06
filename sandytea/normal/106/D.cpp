//program 106D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

char Map[1001][1001];
int D[100000],Step[100000];
int SumX[1001][1001],SumY[1001][1001];

bool Check(int X,int Y,int Count,int M,int N)
{
  for(int i=0;i<Count;i++)
    {
      int X0=X,Y0=Y;
      if(D[i]==0)X-=Step[i];
      if(D[i]==1)X+=Step[i];
      if(D[i]==2)Y+=Step[i];
      if(D[i]==3)Y-=Step[i];
      if(X<=0||X>M||Y<=0||Y>N)return false;
      if(X==X0&&(SumX[X][max(Y,Y0)]!=SumX[X][min(Y,Y0)-1]))return false;
      if(Y==Y0&&(SumY[max(X,X0)][Y]!=SumY[min(X,X0)-1][Y]))return false;
    }
  return true;
}

int main()
{
  int M,N;cin>>M>>N;
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      while(Map[i][j]=getchar(),Map[i][j]==' '||Map[i][j]==10);
  memset(SumX,0,sizeof(SumX));
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      SumX[i][j]=SumX[i][j-1]+(Map[i][j]=='#');
  memset(SumY,0,sizeof(SumY));
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      SumY[i][j]=SumY[i-1][j]+(Map[i][j]=='#');
  int Count;cin>>Count;
  for(int i=0;i<Count;i++)
    {
      char c;while(c=getchar(),c!='N'&&c!='S'&&c!='E'&&c!='W');
      if(c=='N')D[i]=0;
      else if(c=='S')D[i]=1;
      else if(c=='E')D[i]=2;
      else if(c=='W')D[i]=3;
      cin>>Step[i];
    }
  int Total=0;char Ans[26];
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      if(Map[i][j]>='A'&&Map[i][j]<='Z')
        if(Check(i,j,Count,M,N))
          Ans[Total++]=Map[i][j];
  sort(Ans,Ans+Total);
  if(!Total)
    cout<<"no solution";
  else
    for(int i=0;i<Total;i++)putchar(Ans[i]);
  putchar('\n');
  return 0;
}