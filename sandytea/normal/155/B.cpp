//program 155B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct CardType
{
  int X,Y;
};

bool operator <(CardType A,CardType B)
{
  if(A.Y>B.Y)return true;
  if(A.Y<B.Y)return false;
  return A.X>B.X;
}

int main()
{
  int N;cin>>N;CardType Card[1000];
  for(int i=0;i<N;i++)cin>>Card[i].X>>Card[i].Y;
  sort(Card,Card+N);
  int Ans=0,Count=1;
  for(int i=0;i<N&&Count;i++){Ans+=Card[i].X;Count+=Card[i].Y-1;}
  cout<<Ans<<endl;
  return 0;
}