//program 115B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  int N,M;cin>>N>>M;
  int L[150],R[150];
  for(int i=0;i<N;i++)
    {
      L[i]=inf;R[i]=-inf;
      string S;cin>>S;
      for(int j=0;j<M;j++)
        if(S[j]=='W')
          {
            L[i]=min(L[i],j);
            R[i]=max(R[i],j);
          }
    }
  int Ans=0,X=0,Max=0;
  for(int i=0;i<N;i++)
    if(L[i]<=R[i])
      {
        Max=i;
        if(i%2==0)
          {Ans+=abs(X-L[i])+R[i]-L[i];X=R[i];}
        else
          {Ans+=abs(X-R[i])+R[i]-L[i];X=L[i];}
      }
  cout<<Ans+Max<<endl;
  return 0;
}