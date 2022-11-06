//program 136B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[2][20];

void Change(int T,int P)
{
  for(int i=0;i<20;i++){A[P][i]=T%3;T/=3;}
}

int main()
{
  int X,Y;cin>>X>>Y;
  Change(X,0);Change(Y,1);
  int Ans[20];
  for(int i=0;i<20;i++)
    for(int j=0;j<3;j++)
      if((A[0][i]+j)%3==A[1][i])
        Ans[i]=j;
  int T=0;
  for(int i=19;i>=0;i--)T=T*3+Ans[i];
  cout<<T<<endl;
  return 0;
}