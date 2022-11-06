//program 112E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int F[41][64][64];

int main()
{
  int M,N;cin>>M>>N;if(M<N)swap(M,N);
  int Full=(1<<N)-1;
  for(int i=0;i<=M;i++)
    for(int Last=0;Last<=Full;Last++)
      for(int Mask=0;Mask<=Full;Mask++)
        F[i][Last][Mask]=inf;
  for(int i=0;i<=Full;i++)F[M][Full][i]=0;
  int Total[64];Total[0]=0;for(int i=1;i<=Full;i++)Total[i]=Total[i^(i&(-i))]+1;
  for(int i=M-1;i>=0;i--)
    for(int Last=0;Last<=Full;Last++)
      for(int Mask=0;Mask<=Full;Mask++)
        {
          F[i][Last][Mask]=inf;
          for(int Next=0;Next<=Full;Next++)
            if((Last|Next)==Full)
              F[i][Last][Mask]=min(F[i][Last][Mask],F[i+1][(Mask|Next|(Next>>1)|(Next<<1))&Full][Next]+Total[Next]);
        }
  cout<<M*N-F[0][(1<<N)-1][0]<<endl;
  return 0;
}