//program 140A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const double pi=3.1415926535;

int main()
{
  double N,R,r;bool Ans;
  scanf("%lf%lf%lf",&N,&R,&r);
  if(N==1)
    Ans=(R>=r);
  else
    {
      double k=sin(pi/N);
      Ans=(k/(k+1)*R+0.00000001>r);
    }
  printf(Ans?"YES\n":"NO\n");
  return 0;
}