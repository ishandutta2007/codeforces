//program 119C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  long long LB,UB;
  int W,Number;
};

bool Flag[50][100][101];
int Best[50][100][101];
long long Max[50][100][101],NextValue[50][100][101];

bool Cmp(DataType A,DataType B)
{
  return A.W<B.W;
}

int main()
{
  int M,N,K;cin>>M>>N>>K;
  DataType Lesson[50];
  for(int i=0;i<N;i++){cin>>Lesson[i].LB>>Lesson[i].UB>>Lesson[i].W;Lesson[i].Number=i+1;}
  sort(Lesson,Lesson+N,Cmp);
  memset(Flag,0,sizeof(Flag));
  memset(Max,0,sizeof(Max));
  for(int i=0;i<N;i++)
    for(int j=0;j<=Lesson[i].UB-Lesson[i].LB;j++)
      Flag[0][i][j]=true;
  for(int i=1;i<M;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<=Lesson[j].UB-Lesson[j].LB;k++)
        for(int Next=j+1;Next<N;Next++)
          if(Lesson[Next].W>Lesson[j].W)
            {
              long long T=Lesson[j].LB+k,L=Lesson[Next].LB,R=Lesson[Next].UB;
              if(L<=T+K&&T+K<=R&&Flag[i-1][Next][T+K-L])
                {
                  Flag[i][j][k]=true;
                  if(T+K+Max[i-1][Next][T+K-L]>Max[i][j][k])
                    {
                      Max[i][j][k]=T+K+Max[i-1][Next][T+K-L];
                      Best[i][j][k]=Next;NextValue[i][j][k]=T+K;
                    }
                }
              if(L<=T*K&&T*K<=R&&Flag[i-1][Next][T*K-L])
                {
                  Flag[i][j][k]=true;
                  if(T*K+Max[i-1][Next][T*K-L]>Max[i][j][k])
                    {
                      Max[i][j][k]=T*K+Max[i-1][Next][T*K-L];
                      Best[i][j][k]=Next;NextValue[i][j][k]=T*K;
                    }
                }
            }
  long long Ans=0,Start,Value;
  for(int i=0;i<N;i++)
    for(int j=0;j<=Lesson[i].UB-Lesson[i].LB;j++)
      if(Flag[M-1][i][j]&&Max[M-1][i][j]+j+Lesson[i].LB>Ans)
        {Ans=Max[M-1][i][j]+j+Lesson[i].LB;Start=i;Value=j+Lesson[i].LB;}
  if(!Ans)
    cout<<"NO"<<endl;
  else
    {
      cout<<"YES"<<endl;
      for(int i=M-1;i>=0;i--)
        {
          cout<<Lesson[Start].Number<<' '<<Value<<endl;
          long long NewStart=Best[i][Start][Value-Lesson[Start].LB],NewValue=NextValue[i][Start][Value-Lesson[Start].LB];
          Start=NewStart;Value=NewValue;
        }
    }
  return 0;
}