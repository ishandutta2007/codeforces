//program 126C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool A[2000][2000];

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      {
        char c=getchar();
        while(c!='0'&&c!='1')c=getchar();
        A[i][j]=(c=='1');
      }
  int Ans=0;bool R[2000],C[2000],D[2000];
  memset(R,0,sizeof(R));memset(C,0,sizeof(C));memset(D,0,sizeof(D));
  for(int i=0;i<N;i++)
    for(int j=N-1;j>i;j--)
      if(A[i][j]^R[i]^C[j])
        {R[i]=!R[i];C[j]=!C[j];D[i]=!D[i];D[j]=!D[j];Ans++;}
  memset(R,0,sizeof(R));memset(C,0,sizeof(C));
  for(int i=N-1;i>=0;i--)
    for(int j=0;j<i;j++)
      if(A[i][j]^R[i]^C[j])
        {R[i]=!R[i];C[j]=!C[j];D[i]=!D[i];D[j]=!D[j];Ans++;}
  for(int i=0;i<N;i++)if(A[i][i]^D[i])Ans++;
  cout<<Ans<<endl;
  return 0;
}