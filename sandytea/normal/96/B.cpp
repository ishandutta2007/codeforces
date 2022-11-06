//program 96B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long N;cin>>N;
  int Total=0;long long Lucky[10000];
  for(int i=2;i<=10;i+=2)
    for(int j=0;j<(1<<i);j++)
      {
        long long T=0;int Count=0;
        for(int k=0;k<i;k++)
          {
            T=T*10+((j&(1<<k))?4:7);
            if(j&(1<<k))Count++;
          }
        if(Count==i/2)Lucky[Total++]=T;
      }
  sort(Lucky,Lucky+Total);
  int P=0;while(N>Lucky[P])P++;
  cout<<Lucky[P]<<endl;
  return 0;
}