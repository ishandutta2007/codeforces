//program 148C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,A,B;cin>>N>>A>>B;
  if(N>1&&A==N-1)
    cout<<-1<<endl;
  else if(B)
    {
      int X=1;cout<<X<<endl;
      for(int i=0;i<B;i++){X*=2;cout<<X<<endl;}
      for(int i=0;i<A;i++){X++;cout<<X<<endl;}
      for(int i=0;i<N-A-B-1;i++)cout<<1<<endl;
    }
  else
    {
      cout<<1<<endl;
      if(N>1)for(int i=1;i<=A+1;i++)cout<<i<<endl;
      for(int i=0;i<N-A-2;i++)cout<<1<<endl;
    }
  return 0;
}