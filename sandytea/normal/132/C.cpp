//program 132C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;
bool Visited[100][51][201][2],F[100][51][201][2];

bool OK(int N,int K,int Dist,int Direction)
{
  if(!N)
    {
      if((S[N]=='T'&&K%2)||(S[N]=='F'&&!(K%2)))return(Dist==1&&Direction==1);
      if((S[N]=='F'&&K%2)||(S[N]=='T'&&!(K%2)))return(Dist==0&&Direction==-1);
    }
  int X=Dist+100,Y=(Direction==-1)?0:1;
  if(Visited[N][K][X][Y])return F[N][K][X][Y];
  Visited[N][K][X][Y]=F[N][K][X][Y]=true;
  if(S[N]=='F')
    {
      if(OK(N-1,K,Dist-Direction,Direction))return true;
      if(K&&OK(N-1,K-1,Dist,-Direction))return true;
    }
  else
    {
      if(OK(N-1,K,Dist,-Direction))return true;
      if(K&&OK(N-1,K-1,Dist-Direction,Direction))return true;
    }
  return F[N][K][X][Y]=false;
}

int main()
{
  int K;cin>>S>>K;
  int N=S.size(),Ans=100;
  while(!(OK(N-1,K,-Ans,-1)||OK(N-1,K,-Ans,1)||OK(N-1,K,Ans,-1)||OK(N-1,K,Ans,1)))Ans--;
  cout<<Ans<<endl;
  return 0;
}