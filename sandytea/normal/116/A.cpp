//program 116A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,Ans=0,Sum=0;cin>>N;
  for(int i=0;i<N;i++)
    {
      int X,Y;cin>>X>>Y;
      Sum+=Y-X;Ans=max(Ans,Sum);
    }
  cout<<Ans<<endl;
  return 0;
}