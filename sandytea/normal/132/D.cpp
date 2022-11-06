//program 132D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;
int C[1000001];

int main()
{
  cin>>S;int N=S.size();
  memset(C,0,sizeof(C));
  for(int i=0;i<N;i++)if(S[i]=='1')C[N-1-i]=1;
  for(int i=0;i<=1000000;i++)
    if(C[i]==1)
      {
        int P=i;
        while(i<1000000&&C[i+1]==1)i++;
        if(P<i)
          {
            C[P]=-1;
            while(P++<i)C[P]=0;
            C[i+1]=1;
          }
      }
  int Ans=0;
  for(int i=1000000;i>=0;i--)if(C[i])Ans++;
  cout<<Ans<<endl;
  for(int i=1000000;i>=0;i--)
    {
      if(C[i]==1)printf("+2^%d\n",i);
      if(C[i]==-1)printf("-2^%d\n",i);
    }
  return 0;
}