//program 111B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int Last[100001];

int main()
{
  int N;cin>>N;
  for(int i=1;i<=100000;i++)Last[i]=-inf;
  for(int i=0;i<N;i++)
    {
      int X,Y;cin>>X>>Y;
      int Ans=0;
      for(int j=1;j*j<=X;j++)
        if(X%j==0)
          {
            if(Last[j]<i-Y)Ans++;
            if(j*j<X&&Last[X/j]<i-Y)Ans++;
            Last[j]=Last[X/j]=i;
          }
      cout<<Ans<<endl;
    }
  return 0;
}