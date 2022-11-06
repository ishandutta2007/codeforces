//program 94B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int M;cin>>M;
  bool G[5][5];memset(G,0,sizeof(G));
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      G[X][Y]=G[Y][X]=true;
    }
  bool Ans=false;
  for(int i=0;i<3;i++)
    for(int j=i+1;j<4;j++)
      for(int k=j+1;k<5;k++)
        if((G[i][j]&&G[j][k]&&G[k][i])||(!G[i][j]&&!G[j][k]&&!G[k][i]))
          Ans=true;
  cout<<(Ans?"WIN":"FAIL")<<endl;
  return 0;
}