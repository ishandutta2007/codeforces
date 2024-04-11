//program 148B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const double eps=1e-9;

int main()
{
  double V1,V2,T0,T1,C;
  cin>>V1>>V2>>T0>>T1>>C;
  double A=T0*V1,B=0;int Ans=0;
  if(V1<V2)
    while(A+eps<C)
      {
        double T=(A-B)/(V2-V1);A+=T*V1;B+=T*V2;
        if(A+eps<C){Ans++;A+=(B/V2+T1)*V1;B=0;}
      }
  cout<<Ans<<endl;
  return 0;
}