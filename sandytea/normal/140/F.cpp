//program 140F

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Point
{
  long long X,Y;
};

const double eps=1e-9;

int N;
Point P[200000];
long long X[1000],Y[1000];

bool Cmp(Point A,Point B)
{
  if(A.X<B.X)return true;
  if(A.X>B.X)return false;
  return A.Y<B.Y;
}

bool Bigger(long long X1,long long Y1,long long X2,long long Y2)
{
  if(X1>X2)return true;
  if(X1<X2)return false;
  return Y1>Y2;
}

int Count(long long X,long long Y)
{
  int T=N-1,Sum=0;
  for(int i=0;i<N;i++)
    {
      while(T>=0&&Bigger(P[T].X,P[T].Y,X-P[i].X,Y-P[i].Y))T--;
      if(P[T].X+P[i].X==X&&P[T].Y+P[i].Y==Y){if(i<T)Sum+=2;if(i==T)Sum++;T--;}
    }
  return N-Sum;
}

bool Equal(double A,double B)
{
  double T=A-B;
  if(T<0)T=-T;
  return T<eps;
}

int main()
{
  int K;cin>>N>>K;if(K>=N){cout<<-1<<endl;return 0;}
  for(int i=0;i<N;i++)cin>>P[i].X>>P[i].Y;
  sort(P,P+N,Cmp);
  int Ans=0;
  for(int i=0;i<=K;i++)
    for(int j=N-K-1;j<N;j++)
      {
        long long X0=P[i].X+P[j].X,Y0=P[i].Y+P[j].Y;
        if(Count(X0,Y0)<=K)
          {
            bool Flag=true;
            for(int k=0;Flag&&k<Ans;k++)
              if(X0==X[k]&&Y0==Y[k])Flag=false;
            if(Flag){X[Ans]=X0;Y[Ans]=Y0;Ans++;}
          }
      }
  cout<<Ans<<endl;
  for(int i=0;i<Ans;i++)printf("%0.1lf %0.1lf\n",X[i]*0.5,Y[i]*0.5);
  return 0;
}