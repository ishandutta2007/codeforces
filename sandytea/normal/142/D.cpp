//program 142D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int M,N,K;scanf("%d%d%d",&M,&N,&K);
  bool F1=true,F2=true;int Total=0,Data[100];
  for(int i=0;i<M;i++)
    {
      int p=-1,q=-1;bool Free=false;
      for(int j=0;j<N;j++)
        {
          char c=getchar();while(c!='G'&&c!='R'&&c!='-')c=getchar();
          if(c=='G')p=j;if(c=='R')q=j;if(c=='-')Free=true;
        }
      if(p!=-1&&q!=-1)Data[Total++]=abs(p-q)-1;
      else if(p==-1&&q!=-1&&Free)F1=false;
      else if(q==-1&&p!=-1&&Free)F2=false;
    }
  if(!F1&&!F2)
    printf("Draw\n");
  else if(F1&&!F2)
    printf("First\n");
  else if(F2&&!F1)
    printf("Second\n");
  else
    {
      bool Flag=false;
      for(int Round=0;Round<10;Round++)
        {
          int Sum=0;
          for(int i=0;i<Total;i++){Sum+=Data[i]%2;Data[i]/=2;}
          if(Sum%(K+1))Flag=true;
        }
      printf(Flag?"First\n":"Second\n");
    }
  return 0;
};