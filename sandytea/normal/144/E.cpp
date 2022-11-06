//program 144E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  int L,R,Num;
};

int Size;
DataType Data[100000];
int Heap[100001],Ans[100000];

bool Cmp(DataType A,DataType B)
{
  return A.L<B.L;
}

void Swap(int T)
{
  int Tmp=Heap[T];Heap[T]=Heap[T/2];Heap[T/2]=Tmp;
}

void Add(int X)
{
  Heap[++Size]=X;
  int P=Size;
  while(P>1&&Data[Heap[P]].R<Data[Heap[P/2]].R){Swap(P);P/=2;}
}

void Delete()
{
  Heap[1]=Heap[Size--];int P=2;
  while(P<=Size)
    {
      if(Data[Heap[P]].R>=Data[Heap[P/2]].R)
        if(P==Size||Data[Heap[P+1]].R>=Data[Heap[P/2]].R)
          return;
      if(P<Size&&Data[Heap[P+1]].R<Data[Heap[P]].R)P++;
      Swap(P);P*=2;
    }
}

int main()
{
  int N,M;scanf("%d%d",&N,&M);
  for(int i=0;i<M;i++)
    {
      int X,Y;scanf("%d%d",&X,&Y);
      Data[i].L=N+1-X;Data[i].R=Y;Data[i].Num=i+1;
    }
  sort(Data,Data+M,Cmp);
  int Total=Size=0;
  for(int i=1,j=0;i<=N;i++)
    {
      while(j<M&&Data[j].L==i)Add(j++);
      while(Size&&Data[Heap[1]].R<i)Delete();
      if(Size){Ans[Total++]=Data[Heap[1]].Num;Delete();}
    }
  printf("%d\n",Total);
  for(int i=0;i<Total;i++)
    {
      printf("%d",Ans[i]);
      putchar((i==Total-1)?'\n':' ');
    }
  return 0;
}