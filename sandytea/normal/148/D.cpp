//program 148D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

double F[1001][1001];
bool Flag[1001][1001];

double Dragon(int White,int Black);

double Princess(int White,int Black)
{
  if(!White&&!Black)return 0;
  if(Flag[White][Black])return F[White][Black];
  Flag[White][Black]=true;
  int Total=White+Black;
  F[White][Black]=double(White)/Total;
  if(Black)F[White][Black]+=double(Black)/Total*(1-Dragon(White,Black-1));
  return F[White][Black];
}

double Dragon(int White,int Black)
{
  if(!White&&!Black)return 1;
  if(Flag[White][Black])return F[White][Black];
  Flag[White][Black]=true;
  int Total=White+Black;
  F[White][Black]=double(White)/Total;
  if(White&&Black)F[White][Black]+=double(Black)/Total*White/(Total-1)*(1-Princess(White-1,Black-1));
  if(Black>=2)
    F[White][Black]+=double(Black)/Total*(Black-1)/(Total-1)*(1-Princess(White,Black-2));
  else if(!White)
    F[White][Black]+=double(Black)/Total;
  return F[White][Black];
}

int main()
{
  int White,Black;cin>>White>>Black;
  memset(Flag,0,sizeof(Flag));
  printf("%0.10lf\n",Princess(White,Black));
  return 0;
}