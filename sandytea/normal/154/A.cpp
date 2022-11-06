//program 154A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

string S;
int F[100000][26];

int main()
{
  int M;cin>>S>>M;int N=S.size();
  for(int i=0;i<N;i++)S[i]-=97;
  bool G[26][26];memset(G,0,sizeof(G));
  while(M--)
    {
      string T;cin>>T;
      int X=T[0]-97,Y=T[1]-97;
      G[X][Y]=G[Y][X]=true;
    }
  for(int i=0;i<26;i++)F[0][i]=(i==S[0])?0:inf;
  for(int i=1;i<N;i++)
    for(int j=0;j<26;j++)
      {
        F[i][j]=F[i-1][j]+1;
        if(j==S[i])
          {
            F[i][j]=min(F[i][j],i);
            for(int k=0;k<26;k++)
              if(!G[j][k])
                F[i][j]=min(F[i][j],F[i-1][k]);
          }
      }
  int Ans=inf;
  for(int i=0;i<26;i++)Ans=min(Ans,F[N-1][i]);
  cout<<Ans<<endl;
  return 0;
}