//program 98C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const double eps=1e-8;

double F(double A,double B,double L,double T)
{
  return (A*T+B*sqrt(L*L-T*T)-T*sqrt(L*L-T*T))/L;
}

double GetAns(double A,double B,double L)
{
  if(L<=A)return min(B,L);
  if(L<=B)return min(A,L);
  double Left=0,Right=L;
  while(Right-Left>eps)
    {
      double M1=(Left*2+Right)/3,M2=(Left+Right*2)/3;
      if(F(A,B,L,M1)>F(A,B,L,M2))Left=M1;else Right=M2;
    }
  return F(A,B,L,(Left+Right)/2);
}

int main()
{
  double A,B,L;
  cin>>A>>B>>L;
  double Ans=GetAns(A,B,L);
  if(Ans<eps)
    cout<<"My poor head =("<<endl;
  else
    printf("%0.10lf\n",Ans);
  return 0;
}