//program 137D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

string S;
int G[500][500],F[501][500],V[501][500];

void Print(int L,int R)
{
  int i=L,j=R;
  while(i<j)S[i++]=S[j--];
  while(L<=R)putchar(S[L++]);
}

int main()
{
  int N,K;
  cin>>S>>K;N=S.size();
  for(int i=0;i<N;i++)G[i][i]=0;
  for(int i=1;i<N;i++)G[i][i-1]=0;
  for(int Len=1;Len<N;Len++)
    for(int i=0,j=Len;j<N;i++,j++)
      G[i][j]=(S[i]==S[j])?G[i+1][j-1]:(G[i+1][j-1]+1);
  for(int i=0;i<N;i++)F[1][i]=G[0][i];
  for(int i=2;i<=K;i++)
    for(int j=0;j<N;j++)
      {
        F[i][j]=inf;
        for(int k=0;k<j;k++)
          if(F[i-1][k]+G[k+1][j]<F[i][j])
            {
              F[i][j]=F[i-1][k]+G[k+1][j];
              V[i][j]=k;
            }
      }
  int Ans=inf,Best;
  for(int i=1;i<=K;i++)
    if(F[i][N-1]<Ans)
      {
        Ans=F[i][N-1];
        Best=i;
      }
  cout<<Ans<<endl;
  int Top=1,Cut[500];Cut[0]=N-1;
  while(Best>1)
    {
      Cut[Top]=V[Best][Cut[Top-1]];
      Top++;Best--;
    }
  Cut[Top]=-1;
  while(Top--)
    {
      Print(Cut[Top+1]+1,Cut[Top]);
      putchar(Top?'+':'\n');
    }
  return 0;
}