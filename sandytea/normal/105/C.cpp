//program 105C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

struct ItemType
{
  string Name;
  int A,B,C,Size,Type;
};

struct ElfType
{
  string Name,Place;
  int Value,Type;
};

bool operator <(ElfType A,ElfType B)
{
  return (A.Type==B.Type)?(A.Value>B.Value):(A.Type<B.Type);
}

ItemType Item[100];
ElfType Elf[1000];
bool Used[1000];

void Output1(int T,int M)
{
  cout<<Item[T].Name<<' ';
  int Count=0;string A[10];
  for(int i=0;i<M;i++)
    if(Elf[i].Place==Item[T].Name)
      A[Count++]=Elf[i].Name;
  cout<<Count;
  for(int i=0;i<Count;i++)cout<<' '<<A[i];
  putchar('\n');
}

void Output2(int T,int M,int N)
{
  cout<<Item[T].Name<<' ';
  int Count=0;string A[10];
  for(int i=0;i<M;i++)
    if(Elf[i].Type==Item[T].Type&&Count<N)
      A[Count++]=Elf[i].Name;
  for(int i=0;i<M;i++)
    if(!Used[i]&&Count<Item[T].Size)
      {Used[i]=true;A[Count++]=Elf[i].Name;}
  cout<<Count;
  for(int i=0;i<Count;i++)cout<<' '<<A[i];
  putchar('\n');
}

int main()
{
  int N;cin>>N;
  int TotalSize=0;
  map<string,int> Number;
  for(int i=0;i<N;i++)
    {
      string T;cin>>Item[i].Name>>T>>Item[i].A>>Item[i].B>>Item[i].C>>Item[i].Size;
      Number[Item[i].Name]=i;
      if(T=="weapon")Item[i].Type=0;
      else if(T=="armor")Item[i].Type=1;
      else if(T=="orb")Item[i].Type=2;
      TotalSize+=Item[i].Size;
    }
  int M;cin>>M;
  for(int i=0;i<M;i++)
    {
      string T;cin>>Elf[i].Name>>T>>Elf[i].Value>>Elf[i].Place;
      if(T=="gladiator")Elf[i].Type=0;
      else if(T=="sentry")Elf[i].Type=1;
      else if(T=="physician")Elf[i].Type=2;
    }
  if(TotalSize==M)
    {
      for(int i=0;i<M;i++)
        {
          if(Elf[i].Type==0)Item[Number[Elf[i].Place]].A+=Elf[i].Value;
          if(Elf[i].Type==1)Item[Number[Elf[i].Place]].B+=Elf[i].Value;
          if(Elf[i].Type==2)Item[Number[Elf[i].Place]].C+=Elf[i].Value;
        }
      int Ans0,Ans1,Ans2,Max0=-1,Max1=-1,Max2=-1;
      for(int i=0;i<N;i++)
        {
          if(Item[i].Type==0&&Item[i].A>Max0){Max0=Item[i].A;Ans0=i;}
          if(Item[i].Type==1&&Item[i].B>Max1){Max1=Item[i].B;Ans1=i;}
          if(Item[i].Type==2&&Item[i].C>Max2){Max2=Item[i].C;Ans2=i;}
        }
      Output1(Ans0,M);Output1(Ans1,M);Output1(Ans2,M);
    }
  else
    {
      sort(Elf,Elf+M);
      int Count0=0,Count1=0,Count2=0;
      int Sum0[1001],Sum1[1001],Sum2[1001];
      Sum0[0]=Sum1[0]=Sum2[0]=0;
      for(int i=0;i<M;i++)
        {
          if(Elf[i].Type==0){Count0++;Sum0[Count0]=Sum0[Count0-1]+Elf[i].Value;}
          if(Elf[i].Type==1){Count1++;Sum1[Count1]=Sum1[Count1-1]+Elf[i].Value;}
          if(Elf[i].Type==2){Count2++;Sum2[Count2]=Sum2[Count2-1]+Elf[i].Value;}
        }
      int Ans0,Ans1,Ans2,Max0=-1,Max1=-1,Max2=-1;
      for(int i=0;i<N;i++)
        {
          int T;
          if(Item[i].Type==0)
            {
              T=Item[i].A+Sum0[min(Count0,Item[i].Size)];
              if(T>Max0){Max0=T;Ans0=i;}
            }
          if(Item[i].Type==1)
            {
              T=Item[i].B+Sum1[min(Count1,Item[i].Size)];
              if(T>Max1){Max1=T;Ans1=i;}
            }
          if(Item[i].Type==2)
            {
              T=Item[i].C+Sum2[min(Count2,Item[i].Size)];
              if(T>Max2){Max2=T;Ans2=i;}
            }
        }
      memset(Used,0,sizeof(Used));
      int P=0;
      for(int i=0;i<min(Item[Ans0].Size,Count0);i++)Used[P+i]=true;
      while(P<M&&Elf[P].Type==0)P++;
      for(int i=0;i<min(Item[Ans1].Size,Count1);i++)Used[P+i]=true;
      while(P<M&&Elf[P].Type==1)P++;
      for(int i=0;i<min(Item[Ans2].Size,Count2);i++)Used[P+i]=true;
      Output2(Ans0,M,min(Item[Ans0].Size,Count0));
      Output2(Ans1,M,min(Item[Ans1].Size,Count1));
      Output2(Ans2,M,min(Item[Ans2].Size,Count2));
    }
  return 0;
}