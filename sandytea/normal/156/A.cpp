//program 156A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S,T;cin>>S>>T;
  int N=S.size(),M=T.size(),Ans=0;
  for(int i=-M,j=0;i<N;i++,j++)
    {
      int Count=0;
      for(int k=max(i,0);k<=min(j,N-1);k++)if(S[k]==T[k-i])Count++;
      Ans=max(Ans,Count);
    }
  cout<<M-Ans<<endl;
  return 0;
}