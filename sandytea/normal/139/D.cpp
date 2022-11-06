//program 139D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

void Output(int x,int y)
{
  while(y--)putchar(x+48);
}

int main()
{
  int A[10],B[10];memset(A,0,sizeof(A));memset(B,0,sizeof(B));
  char c;while(c=getchar(),c>='0'&&c<='9'){A[c-48]++;B[c-48]++;}
  int Max=-1,Best;
  for(int X=1;X<=5;X++)
    if(A[X]&&B[10-X])
      {
        int C[10],D[10];
        for(int i=0;i<10;i++){C[i]=A[i];D[i]=B[i];}
        C[X]--;D[10-X]--;
        int Sum=0;
        for(int i=0;i<10;i++)
          {
            int Tmp=min(C[i],D[9-i]);
            C[i]-=Tmp;D[9-i]-=Tmp;Sum+=Tmp;
          }
        Sum+=min(C[0],D[0]);
        if(Sum>Max){Max=Sum;Best=X;}
      }
  if(Max==-1)
    {
      for(int i=9;i>=0;i--)Output(i,A[i]);putchar('\n');
      for(int i=9;i>=0;i--)Output(i,B[i]);putchar('\n');
    }
  else
    {
      A[Best]--;B[10-Best]--;int C[10];
      for(int i=0;i<10;i++)
        {
          C[i]=min(A[i],B[9-i]);
          A[i]-=C[i];B[9-i]-=C[i];
        }
      int Zero=min(A[0],B[0]);A[0]-=Zero;B[0]-=Zero;
      for(int i=9;i>=0;i--)Output(i,A[i]);
      for(int i=0;i<10;i++)Output(i,C[i]);
      putchar(Best+48);Output(0,Zero);putchar('\n');
      for(int i=9;i>=0;i--)Output(i,B[i]);
      for(int i=0;i<10;i++)Output(9-i,C[i]);
      putchar(58-Best);Output(0,Zero);putchar('\n');
    }
  return 0;
}