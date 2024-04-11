//program 152B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  long long M,N,X,Y,K,Ans=0;cin>>M>>N>>X>>Y>>K;
  while(K--)
    {
      long long P,Q,Tmp=inf;cin>>P>>Q;
      if(P>0)Tmp=min(Tmp,(M-X)/P);
      if(P<0)Tmp=min(Tmp,(X-1)/(-P));
      if(Q>0)Tmp=min(Tmp,(N-Y)/Q);
      if(Q<0)Tmp=min(Tmp,(Y-1)/(-Q));
      Ans+=Tmp;X+=Tmp*P;Y+=Tmp*Q;
    }
  cout<<Ans<<endl;
  return 0;
}