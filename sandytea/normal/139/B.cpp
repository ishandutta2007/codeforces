//program 139B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,H[500],Len[500];cin>>N;
  for(int i=0;i<N;i++){int A,B;cin>>A>>B>>H[i];Len[i]=(A+B)*2;}
  int M,X[500],Y[500],P[500];cin>>M;
  for(int i=0;i<M;i++)cin>>X[i]>>Y[i]>>P[i];
  int Ans=0;
  for(int i=0;i<N;i++)
    {
      int Best=1<<30;
      for(int j=0;j<M;j++)
        if(X[j]>=H[i])
          Best=min(Best,((Len[i]-1)/(X[j]/H[i]*Y[j])+1)*P[j]);
      Ans+=Best;
    }
  cout<<Ans<<endl;
  return 0;
}