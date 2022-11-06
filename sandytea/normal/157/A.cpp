//program 157A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int X[30],Y[30];memset(X,0,sizeof(X));memset(Y,0,sizeof(Y));
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      {
        int T;cin>>T;
        X[i]+=T;Y[j]+=T;
      }
  int Ans=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(X[i]<Y[j])Ans++;
  cout<<Ans<<endl;
  return 0;
}