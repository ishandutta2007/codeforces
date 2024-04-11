//program 161E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Prime[100000];
int Count1[10][10][10][10],Count2[10][10][10][10],Count3[10][10][10][10],Count4[10][10][10][10];

void Init()
{
  memset(Prime,0,sizeof(Prime));
  for(int i=2;i<100000;i++)
    {
      bool Flag=true;
      for(int j=2;Flag&&j*j<=i;j++)Flag=i%j;
      Prime[i]=Flag;
    }
  for(int A=0;A<10;A++)
    for(int B=0;B<10;B++)
      for(int C=0;C<10;C++)
        for(int D=0;D<10;D++)
          for(int E=0;E<10;E++)
            if(Prime[A*10000+B*1000+C*100+D*10+E])
              {
                Count1[A][C][D][E]++;
                Count2[A][B][D][E]++;
                Count3[A][B][C][E]++;
                Count4[A][B][C][D]++;
              }
}

int Two(int X)
{
  int A=X%10,Ans=0;
  for(int i=0;i<10;i++)if(Prime[A*10+i])Ans++;
  return Ans;
}

int Three(int X)
{
  int A=X/10%10,B=X%10,Ans=0;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      if(Prime[A*100+i*10+j])
        for(int k=0;k<10;k++)
          if(Prime[B*100+j*10+k])
            Ans++;
  return Ans;
}

int Four(int X)
{
  int A=X/100%10,B=X/10%10,C=X%10,Ans=0;
  for(int D=0;D<10;D++)
    for(int E=0;E<10;E++)
      for(int F=0;F<10;F++)
        if(Prime[A*1000+D*100+E*10+F])
          for(int G=0;G<10;G++)
            for(int H=0;H<10;H++)
              if(Prime[B*1000+E*100+G*10+H])
                for(int I=0;I<10;I++)
                  if(Prime[C*1000+F*100+H*10+I])
                    Ans++;
  return Ans;
}

int Five(int X)
{
  int A=X/1000%10,B=X/100%10,C=X/10%10,D=X%10,Ans=0;
  for(int E=0;E<10;E++)
    for(int F=0;F<10;F++)
      for(int G=0;G<10;G++)
        if(Count1[A][E][F][G])
          for(int H=0;H<10;H++)
            for(int I=0;I<10;I++)
              if(Count2[B][E][H][I])
                for(int J=0;J<10;J++)
                  Ans+=Count1[A][E][F][G]*Count2[B][E][H][I]*Count3[C][F][H][J]*Count4[D][G][I][J];
  return Ans;
}

int GetAns(int X)
{
  if(X<100)return Two(X);
  if(X<1000)return Three(X);
  if(X<10000)return Four(X);
  return Five(X);
}

int main()
{
  Init();int Test;cin>>Test;
  while(Test--){int X;cin>>X;cout<<GetAns(X)<<endl;}
  return 0;
}