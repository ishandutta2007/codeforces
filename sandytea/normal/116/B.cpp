//program 116B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int M,N;cin>>M>>N;
  string Map[10];for(int i=0;i<M;i++)cin>>Map[i];
  int Ans=0;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      if(Map[i][j]=='W')
        {
          bool Flag=false;
          if(i&&Map[i-1][j]=='P')Flag=true;
          if(i+1<M&&Map[i+1][j]=='P')Flag=true;
          if(j&&Map[i][j-1]=='P')Flag=true;
          if(j+1<N&&Map[i][j+1]=='P')Flag=true;
          if(Flag)Ans++;
        }
  cout<<Ans<<endl;
  return 0;
}