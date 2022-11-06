//program 121E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Rest[10001];
int Data[100000];
int Delta[300000],Min[300000],CountMin[300000];

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int x=c-48;while(c=getchar(),c>='0'&&c<='9')x=x*10+c-48;
  return x;
}

void Output(int T)
{
  int Len=0,Data[20];
  while(T){Data[Len++]=T%10;T/=10;}
  if(!Len)Data[Len++]=0;
  while(Len--)putchar(Data[Len]+48);putchar('\n');
}

bool Lucky(int T)
{
  return T?((T%10==4||T%10==7)?Lucky(T/10):false):true;
}

void Check(int P,int Left,int Right)
{
  if(!Delta[P])return;Min[P]-=Delta[P];
  if(Left!=Right){Delta[P<<1]+=Delta[P];Delta[(P<<1)^1]+=Delta[P];}
  Delta[P]=0;
}

void Update(int P,int Left,int Right)
{
  int Mid=(Left+Right)/2;Check(P<<1,Left,Mid);Check((P<<1)^1,Mid+1,Right);
  Min[P]=min(Min[P<<1],Min[(P<<1)^1]);CountMin[P]=0;
  if(Min[P]==Min[P<<1])CountMin[P]+=CountMin[P<<1];
  if(Min[P]==Min[(P<<1)^1])CountMin[P]+=CountMin[(P<<1)^1];
}

void BuildTree(int P,int L,int R)
{
  int Mid=(L+R)/2;
  if(L==R)
    {
      Min[P]=Rest[Data[L]];
      CountMin[P]=1;
    }
  else
    {
      BuildTree(P<<1,L,Mid);
      BuildTree((P<<1)^1,Mid+1,R);
      Update(P,L,R);
    }
}

int Count(int P,int Left,int Right,int L,int R)
{
  Check(P,Left,Right);
  if(L==Left&&R==Right)return Min[P]?0:CountMin[P];
  int Mid=(Left+Right)/2;
  if(R<=Mid)return Count(P<<1,Left,Mid,L,R);
  if(L>Mid)return Count((P<<1)^1,Mid+1,Right,L,R);
  return Count(P<<1,Left,Mid,L,Mid)+Count((P<<1)^1,Mid+1,Right,Mid+1,R);
}

void Add(int P,int Left,int Right,int L,int R,int D)
{
  if(L==Left&&R==Right){Delta[P]+=D;return;}
  int Mid=(Left+Right)/2;
  if(R<=Mid)Add(P<<1,Left,Mid,L,R,D);
  else if(L>Mid)Add((P<<1)^1,Mid+1,Right,L,R,D);
  else {Add(P<<1,Left,Mid,L,Mid,D);Add((P<<1)^1,Mid+1,Right,Mid+1,R,D);}
  Update(P,Left,Right);
}

void CheckZero(int P,int Left,int Right)
{
  Check(P,Left,Right);
  if(Left==Right)
    {
      Data[Left]+=Rest[Data[Left]]-Min[P];
      Min[P]=Rest[Data[Left]];return;
    }
  int Mid=(Left+Right)/2;
  if(Min[P<<1]-Delta[P<<1]<0)CheckZero(P<<1,Left,Mid);else CheckZero((P<<1)^1,Mid+1,Right);
  Update(P,Left,Right);
}

int main()
{
  int N=GetNumber(),M=GetNumber();
  int Last=44444;for(int i=10000;i;i--){if(Lucky(i))Last=i;Rest[i]=Last-i;}
  for(int i=0;i<N;i++)Data[i]=GetNumber();
  BuildTree(1,0,N-1);memset(Delta,0,sizeof(Delta));
  while(M--)
    {
      char c1=getchar();while(c1!='a'&&c1!='c')c1=getchar();
      char c2=getchar();while(c2!=' ')c2=getchar();
      if(c1=='a')
        {
          int L=GetNumber()-1,R=GetNumber()-1,D=GetNumber();
          Add(1,0,N-1,L,R,D);while(Min[1]-Delta[1]<0)CheckZero(1,0,N-1);
        }
      else
        {
          int L=GetNumber()-1,R=GetNumber()-1;
          Output(Count(1,0,N-1,L,R));
        }
    }
  return 0;
}