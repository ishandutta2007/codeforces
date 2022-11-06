//program 95B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[100000],Ans[100000];

string Get(int X,int N)
{
  string S;
  while(N--)S+=X+48;
  return S;
}

bool DFS(int Depth,int Four,int Seven,bool Flag)
{
  if(!Four&&!Seven)return true;
  if(Flag)
    if(Four)
      {Ans[Depth]=4;return DFS(Depth+1,Four-1,Seven,Flag);}
    else
      {Ans[Depth]=7;return DFS(Depth+1,Four,Seven-1,Flag);}
  if(Four&&A[Depth]<4&&DFS(Depth+1,Four-1,Seven,true)){Ans[Depth]=4;return true;}
  if(Four&&A[Depth]==4&&DFS(Depth+1,Four-1,Seven,false)){Ans[Depth]=4;return true;}
  if(Seven&&A[Depth]<7&&DFS(Depth+1,Four,Seven-1,true)){Ans[Depth]=7;return true;}
  if(Seven&&A[Depth]==7&&DFS(Depth+1,Four,Seven-1,false)){Ans[Depth]=7;return true;}
  return false;
}

int main()
{
  string S;cin>>S;
  int N=S.size();string T=Get(7,N/2)+Get(4,N/2);
  if(S.size()>T.size()||(S.size()==T.size()&&S>T)){cout<<Get(4,N/2+1)+Get(7,N/2+1)<<endl;return 0;}
  for(int i=0;i<N;i++)A[i]=S[i]-48;
  DFS(0,N/2,N/2,false);
  for(int i=0;i<N;i++)cout<<Ans[i];
  putchar('\n');
  return 0;
}