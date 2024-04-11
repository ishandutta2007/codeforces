//program 131F

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Map[500][500];
int Sum[500][500];

int main()
{
  int M,N,K;cin>>M>>N>>K;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      {
        char c=getchar();
        while(c!='0'&&c!='1')c=getchar();
        Map[i][j]=(c=='1');
      }
  memset(Sum,0,sizeof(Sum));
  for(int i=1;i<M;i++)
    for(int j=0;j<N;j++)
      {
        Sum[i][j]=Sum[i-1][j];
        if(i+1<M&&j&&j+1<N)
          if(Map[i][j]&&Map[i-1][j]&&Map[i+1][j]&&Map[i][j-1]&&Map[i][j+1])
            Sum[i][j]++;
      }
  long long Ans=0;
  for(int LB=0;LB<M;LB++)
    for(int UB=LB+2;UB<M;UB++)
      {
        int A[500];
        for(int i=0;i<N;i++)A[i]=Sum[UB-1][i]-Sum[LB][i];
        int P=1,S=0;
        for(int i=1;i<N;i++)
          {
            while(P<N&&S<K)S+=A[P++];
            if(S>=K)Ans+=N-P;S-=A[i];
          }
      }
  cout<<Ans<<endl;
  return 0;
}