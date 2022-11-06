//program 160E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  int X,Y,T,Number;
  bool Type;
};

struct SplayTree
{
  SplayTree *Parent,*Lc,*Rc;
  int X;
  pair<int,int> Data,Min;
};

bool operator <(DataType A,DataType B)
{
  return (A.T==B.T)?(!A.Type&&B.Type):(A.T>B.T);
}

bool operator <(pair<int,int> A,pair<int,int> B)
{
  return A.first<B.first;
}

const int inf=2000000000;
const pair<int,int> None(inf,-1);

int Total;
int Ans[100000];
int XX[400000];
DataType Data[200000];
SplayTree *Tree[400001];

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void Init(int N,int M)
{
  for(int i=0;i<N;i++)
    {
      Data[i].X=GetNumber();
      Data[i].Y=GetNumber();
      Data[i].T=GetNumber();
      Data[i].Number=i+1;
      Data[i].Type=false;
    }
  for(int i=0;i<M;i++)
    {
      Data[N+i].X=GetNumber();
      Data[N+i].Y=GetNumber();
      Data[N+i].T=GetNumber();
      Data[N+i].Number=i;
      Data[N+i].Type=true;
    }
}

int Find(int N,int X)
{
  int Left=0,Right=N-1;
  while(true)
    {
      int Mid=(Left+Right)/2;
      if(XX[Mid]==X)return Mid;
      if(XX[Mid]<X)Left=Mid+1;else Right=Mid-1;
    }
}

void Sort(int N)
{
  sort(Data,Data+N);
  for(int i=0;i<N;i++)
    {
      XX[i*2]=Data[i].X;
      XX[i*2+1]=Data[i].Y;
    }
  sort(XX,XX+N*2);
  Total=0;
  for(int i=0;i<N*2;i++)
    if(!i||XX[i]!=XX[i-1])
      XX[Total++]=XX[i];
  for(int i=0;i<N;i++)
    {
      Data[i].X=Find(Total,Data[i].X)+1;
      Data[i].Y=Find(Total,Data[i].Y)+1;
    }
}

void Update(SplayTree *P)
{
  P->Min=P->Data;
  if(P->Lc!=NULL)P->Min=min(P->Min,P->Lc->Min);
  if(P->Rc!=NULL)P->Min=min(P->Min,P->Rc->Min);
}

void TurnRight(SplayTree *P)
{
  SplayTree *Q;Q=P->Parent;
  P->Parent=Q->Parent;
  if(P->Parent!=NULL)
    if(Q==Q->Parent->Lc)
      Q->Parent->Lc=P;
    else
      Q->Parent->Rc=P;
  Q->Lc=P->Rc;if(P->Rc!=NULL)P->Rc->Parent=Q;
  P->Rc=Q;Q->Parent=P;
  Update(Q);
}

void TurnLeft(SplayTree *P)
{
  SplayTree *Q;Q=P->Parent;
  P->Parent=Q->Parent;
  if(P->Parent!=NULL)
    if(Q==Q->Parent->Lc)
      Q->Parent->Lc=P;
    else
      Q->Parent->Rc=P;
  Q->Rc=P->Lc;if(P->Lc!=NULL)P->Lc->Parent=Q;
  P->Lc=Q;Q->Parent=P;
  Update(Q);
}

void Splay(SplayTree *P)
{
  while(P->Parent!=NULL)
    {
      SplayTree *X,*Y;X=P->Parent;Y=X->Parent;
      if(Y==NULL)
        if(P==X->Lc)
          TurnRight(P);
        else
          TurnLeft(P);
      else
        if(P==X->Lc&&X==Y->Lc){TurnRight(X);TurnRight(P);}
        else if(P==X->Rc&&X==Y->Rc){TurnLeft(X);TurnLeft(P);}
        else if(P==X->Lc&&X==Y->Rc){TurnRight(P);TurnLeft(P);}
        else if(P==X->Rc&&X==Y->Lc){TurnLeft(P);TurnRight(P);}
    }
  Update(P);
}

SplayTree *NewNode(int R,pair<int,int> Time)
{
  SplayTree *P;P=new SplayTree;
  P->Parent=P->Lc=P->Rc=NULL;
  P->X=R;P->Data=P->Min=Time;
  return P;
}

pair<int,int> GetTree(int W,int R)
{
  SplayTree *P,*Q;
  if(Tree[W]==NULL)return None;
  P=Tree[W];while(P->Rc!=NULL)P=P->Rc;
  Splay(P);Tree[W]=P;if(P->X<R)return None;
  P=Tree[W];while(P->Lc!=NULL)P=P->Lc;
  Splay(P);Tree[W]=P;if(P->X>=R)return Tree[W]->Min;
  P=Tree[W];while(P!=NULL){Q=P;if(P->X<R)P=P->Rc;else P=P->Lc;}
  Splay(Q);Tree[W]=Q;
  pair<int,int> Ans=(Q->X>=R)?Q->Data:None;
  if(Q->Rc!=NULL)Ans=min(Ans,Q->Rc->Min);
  return Ans;
}

void AddTree(int W,int R,pair<int,int> Time)
{
  SplayTree *P,*Q;
  if(Tree[W]==NULL){Tree[W]=NewNode(R,Time);return;}
  P=Tree[W];
  while(P!=NULL){Q=P;if(R<P->X)P=P->Lc;else P=P->Rc;}
  if(R<Q->X)
    {
      P=NewNode(R,Time);
      P->Parent=Q;Q->Lc=P;
      Splay(P);Tree[W]=P;
    }
  else
    {
      P=NewNode(R,Time);
      P->Parent=Q;Q->Rc=P;
      Splay(P);Tree[W]=P;
    }
}

pair<int,int> GetAns(int L,int R)
{
  pair<int,int> Ans=None;
  while(L)
    {
      Ans=min(Ans,GetTree(L,R));
      L^=L&(-L);
    }
  return Ans;
}

void Add(int L,int R,pair<int,int> Time)
{
  while(L<=Total)
    {
      AddTree(L,R,Time);
      L+=L&(-L);
    }
}

void Calculate(int N)
{
  for(int i=1;i<=Total;i++)Tree[i]=NULL;
  for(int i=0;i<N;i++)
    if(Data[i].Type)
      Ans[Data[i].Number]=GetAns(Data[i].X,Data[i].Y).second;
    else
      Add(Data[i].X,Data[i].Y,make_pair(Data[i].T,Data[i].Number));
}

void Output(int N)
{
  for(int i=0;i<N;i++)
    cout<<Ans[i]<<((i==N-1)?'\n':' ');
}

int main()
{
  int N=GetNumber(),M=GetNumber();
  Init(N,M);
  Sort(N+M);
  Calculate(N+M);
  Output(M);
  return 0;
}