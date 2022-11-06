//program 104E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct QueryType
{
  int A,B,X;
};

bool operator <(QueryType P,QueryType Q)
{
  return P.B<Q.B;
}

long long Cow[300000],S[300000],Ans[300000];
QueryType Query[300000];

int GetNumber()
{
  char c;while(c=getchar(),c<'0'||c>'9');
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void Output(long long X)
{
  int Len=0,Data[20];
  while(X){Data[Len++]=X%10;X/=10;}
  if(!Len)Data[Len++]=0;
  while(Len--)putchar(Data[Len]+48);
  putchar('\n');
}

int main()
{
  int N=GetNumber();
  for(int i=0;i<N;i++)Cow[i]=GetNumber();
  int M=GetNumber();
  for(int i=0;i<M;i++)
    {
      Query[i].A=GetNumber()-1;
      Query[i].B=GetNumber();
      Query[i].X=i;
    }
  sort(Query,Query+M);
  int MM=int(sqrt(N));
  for(int i=0;i<M;i++)
    if(Query[i].B>MM)
      {
        long long Sum=0;
        for(int j=Query[i].A;j<N;j+=Query[i].B)Sum+=Cow[j];
        Ans[Query[i].X]=Sum;
      }
    else
      {
        int P=i,Q=i+1;while(Q<M&&Query[P].B==Query[Q].B)Q++;i=Q-1;
        for(int j=N-1;j>=0;j--){S[j]=Cow[j];if(j+Query[P].B<N)S[j]+=S[j+Query[P].B];}
        for(int j=P;j<Q;j++)Ans[Query[j].X]=S[Query[j].A];
      }
  for(int i=0;i<M;i++)Output(Ans[i]);
  return 0;
}