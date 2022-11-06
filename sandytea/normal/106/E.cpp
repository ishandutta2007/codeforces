//program 106E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point
{
  double X,Y,Z;
};

const double V[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
const double inf=1000000000;

Point P[100];

double Dist(Point A,Point B)
{
  return sqrt((A.X-B.X)*(A.X-B.X)+(A.Y-B.Y)*(A.Y-B.Y)+(A.Z-B.Z)*(A.Z-B.Z));
}

Point Farthest(Point O,int N)
{
  double Max=-1;int Number;
  for(int i=0;i<N;i++)
    {
      double T=Dist(O,P[i]);
      if(T>Max){Max=T;Number=i;}
    }
  return P[Number];
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)cin>>P[i].X>>P[i].Y>>P[i].Z;
  Point O;O.X=O.Y=O.Z=0;
  double Step=1;
  for(int i=0;i<100000;i++)
    {
      Point P=Farthest(O,N);
      O.X+=(P.X-O.X)*Step;
      O.Y+=(P.Y-O.Y)*Step;
      O.Z+=(P.Z-O.Z)*Step;
      Step*=0.999;
    }
  printf("%0.10lf %0.10lf %0.10lf\n",O.X,O.Y,O.Z);
  return 0;
}