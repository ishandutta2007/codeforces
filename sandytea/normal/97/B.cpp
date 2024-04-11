//program 97B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

struct Point
{
  int X,Y;
};

bool operator <(Point A,Point B)
{
  return (A.X==B.X)?(A.Y<B.Y):(A.X<B.X);
}

Point P[10000];
set<Point> Ans;

void Add(int L,int R)
{
  if(L+1==R)return;
  int Mid=(L+R)/2;
  for(int i=L;i<R;i++)
    Ans.insert((Point){P[(L+R)/2].X,P[i].Y});
  Add(L,Mid);Add(Mid,R);
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)cin>>P[i].X>>P[i].Y;
  for(int i=0;i<N;i++)Ans.insert(P[i]);
  sort(P,P+N);Add(0,N);
  cout<<Ans.size()<<endl;
  for(set<Point>::iterator i=Ans.begin();i!=Ans.end();i++)
    cout<<i->X<<' '<<i->Y<<endl;
  return 0;
}