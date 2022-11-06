//program 155A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  int N;cin>>N;
  int Min=inf,Max=-inf,Ans=0;
  for(int i=0;i<N;i++)
    {
      int X;cin>>X;
      if(i&&(X<Min||X>Max))Ans++;
      Min=min(Min,X);Max=max(Max,X);
    }
  cout<<Ans<<endl;
  return 0;
}