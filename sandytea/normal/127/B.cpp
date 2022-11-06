//program 127B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int Count[100];memset(Count,0,sizeof(Count));
  while(N--){int X;cin>>X;Count[X-1]++;}
  int Ans=0;for(int i=0;i<100;i++)Ans+=Count[i]/2;
  cout<<Ans/2<<endl;
  return 0;
}