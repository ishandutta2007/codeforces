//program 159E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
  int Color,Number;
  long long Height;
};

bool operator <(Data A,Data B)
{
  return (A.Color==B.Color)?(A.Height>B.Height):(A.Color<B.Color);
}

int main()
{
  int N;cin>>N;
  Data A[100000];
  for(int i=0;i<N;i++){cin>>A[i].Color>>A[i].Height;A[i].Number=i+1;}
  sort(A,A+N);
  long long Max[100001][2];int Best[100001][2];memset(Max,0,sizeof(Max));
  int Len=0;long long Sum=0;
  for(int i=0;i<N;i++)
    {
      if(!i||A[i].Color!=A[i-1].Color)Len=Sum=0;
      Len++;Sum+=A[i].Height;
      if(Sum>Max[Len][0])
        {
          Max[Len][1]=Max[Len][0];
          Best[Len][1]=Best[Len][0];
          Max[Len][0]=Sum;Best[Len][0]=i+1-Len;
        }
      else if(Sum>Max[Len][1])
        {
          Max[Len][1]=Sum;
          Best[Len][1]=i+1-Len;
        }
    }
  long long Ans=Max[1][0];int Ans_1=1,Ans_2=0,Rank_1=0,Rank_2;
  for(int i=1;i<=N;i++)
    if(Max[i][0]&&Max[i][1]&&Max[i][0]+Max[i][1]>Ans)
      {Ans=Max[i][0]+Max[i][1];Ans_1=Ans_2=i;}
  for(int i=1;i<N;i++)
    {
      if(Max[i][0]&&Max[i+1][0]&&Max[i][0]+Max[i+1][0]>Ans&&Best[i][0]!=Best[i+1][0])
        {Ans=Max[i][0]+Max[i+1][0];Ans_1=i+1;Ans_2=i;Rank_1=Rank_2=0;}
      if(Max[i][0]&&Max[i+1][1]&&Max[i][0]+Max[i+1][1]>Ans&&Best[i][0]!=Best[i+1][1])
        {Ans=Max[i][0]+Max[i+1][1];Ans_1=i+1;Ans_2=i;Rank_1=1;Rank_2=0;}
      if(Max[i][1]&&Max[i+1][0]&&Max[i][1]+Max[i+1][0]>Ans&&Best[i][1]!=Best[i+1][0])
        {Ans=Max[i][1]+Max[i+1][0];Ans_1=i+1;Ans_2=i;Rank_1=0;Rank_2=1;}
    }
  int Total=0,S[100000];
  if(!Ans_2)
    S[Total++]=A[Best[1][0]].Number;
  else if(Ans_1==Ans_2)
    for(int i=0;i<Ans_1;i++)
      {
        S[Total++]=A[Best[Ans_1][0]+i].Number;
        S[Total++]=A[Best[Ans_2][1]+i].Number;
      }
  else if(Ans_1==Ans_2+1)
    for(int i=0;i<Ans_1;i++)
      {
        S[Total++]=A[Best[Ans_1][Rank_1]+i].Number;
        if(i<Ans_2)S[Total++]=A[Best[Ans_2][Rank_2]+i].Number;
      }
  cout<<Ans<<endl<<Total<<endl;
  for(int i=0;i<Total;i++)cout<<S[i]<<((i==Total-1)?'\n':' ');
  return 0;
}