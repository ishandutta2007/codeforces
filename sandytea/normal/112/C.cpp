//program 112C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long N,X,Y;cin>>N>>X>>Y;
  if(N>Y)
    cout<<-1<<endl;
  else
    {
      long long Max=(Y-N+1)*(Y-N+1)+N-1;
      if(Max<X)
        cout<<-1<<endl;
      else
        for(int i=0;i<N;i++)cout<<(i?1:(Y-N+1))<<endl;
    }
  return 0;
}