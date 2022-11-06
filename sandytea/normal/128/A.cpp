//program 128A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string Map[8];
bool F[8][8][8],Visited[8][8][8];

bool Check(int Time,int X,int Y)
{
  if(X<0||X>=8||Y<0||Y>=8)return false;
  if(X>=Time&&Map[X-Time][Y]=='S')return false;
  if(X>Time&&Map[X-Time-1][Y]=='S')return false;
  return true;
}

bool DFS(int Time,int X,int Y)
{
  if(Time>=8)return true;
  if(Visited[Time][X][Y])return F[Time][X][Y];
  Visited[Time][X][Y]=F[Time][X][Y]=true;
  if(Check(Time,X-1,Y-1)&&DFS(Time+1,X-1,Y-1))return true;
  if(Check(Time,X-1,Y)&&DFS(Time+1,X-1,Y))return true;
  if(Check(Time,X-1,Y+1)&&DFS(Time+1,X-1,Y+1))return true;
  if(Check(Time,X,Y-1)&&DFS(Time+1,X,Y-1))return true;
  if(Check(Time,X,Y)&&DFS(Time+1,X,Y))return true;
  if(Check(Time,X,Y+1)&&DFS(Time+1,X,Y+1))return true;
  if(Check(Time,X+1,Y-1)&&DFS(Time+1,X+1,Y-1))return true;
  if(Check(Time,X+1,Y)&&DFS(Time+1,X+1,Y))return true;
  if(Check(Time,X+1,Y+1)&&DFS(Time+1,X+1,Y+1))return true;
  return F[Time][X][Y]=false;
}

int main()
{
  for(int i=0;i<8;i++)cin>>Map[i];
  memset(Visited,0,sizeof(Visited));
  cout<<(DFS(0,7,0)?"WIN":"LOSE")<<endl;
  return 0;
}