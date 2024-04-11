//program 152A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M;cin>>N>>M;
  int A[100][100],Max[100];memset(Max,0,sizeof(Max));
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      {
        char c=getchar();
        while(c<'0'||c>'9')c=getchar();
        A[i][j]=c-48;Max[j]=max(Max[j],A[i][j]);
      }
  bool Flag[100];memset(Flag,0,sizeof(Flag));
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      if(A[i][j]==Max[j])Flag[i]=true;
  int Ans=0;
  for(int i=0;i<N;i++)if(Flag[i])Ans++;
  cout<<Ans<<endl;
  return 0;
}