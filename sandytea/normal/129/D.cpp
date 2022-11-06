//program 129D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string ST;
int S[100000],A[100000];

int main()
{
  int N,K;cin>>ST>>K;N=ST.size();
  if(K>(long long)N*(N+1)/2)
    {
      cout<<"No such line."<<endl;
      return 0;
    }
  for(int i=0;i<N;i++)S[i]=ST[i]-97;
  int Total=N;for(int i=0;i<N;i++)A[i]=i;
  while(true)
    {
      long long Count[26];memset(Count,0,sizeof(Count));
      for(int i=0;i<Total;i++)Count[S[A[i]]]+=N-A[i];
      int C=0;while(K>Count[C])K-=Count[C++];putchar(C+97);
      int Tmp=Total;Total=0;
      for(int i=0;i<Tmp;i++)
        if(S[A[i]]==C)
          {
            K--;
            if(A[i]+1<N)A[Total++]=A[i]+1;
          }
      if(K<=0)break;
    }
  return 0;
}