//program 137B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  bool Flag[5000];
  memset(Flag,0,sizeof(Flag));
  for(int i=0;i<N;i++)
    {
      int X;cin>>X;
      Flag[X-1]=true;
    }
  int Ans=0;
  for(int i=0;i<N;i++)if(!Flag[i])Ans++;
  cout<<Ans<<endl;
  return 0;
}