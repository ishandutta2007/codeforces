//program 102C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  string S;cin>>S;
  int N=S.size(),K;cin>>K;K=min(K,N);
  int Count[128];memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)Count[S[i]]++;
  int Total=0;
  for(int i='a';i<='z';i++)if(Count[i])Total++;
  while(K>0)
    {
      int Min=inf,Letter;
      for(int i='a';i<='z';i++)
        if(Count[i]>0&&Count[i]<Min)
          {Min=Count[i];Letter=i;}
      Count[Letter]-=min(Min,K);K-=min(Min,K);
      if(!Count[Letter])Total--;
    }
  cout<<Total<<endl;
  for(int i=0;i<N;i++)
    if(Count[S[i]])
      {putchar(S[i]);Count[S[i]]--;}
  putchar('\n');
  return 0;
}