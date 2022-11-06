//program 127C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long T1,T2,X1,X2,T0;
  cin>>T1>>T2>>X1>>X2>>T0;
  if(T0==T2)
    {
      if(T0==T1)
        cout<<X1<<' '<<X2<<endl;
      else
        cout<<"0 "<<X2<<endl;
      return 0;
    }
  long long Ans1=0,Ans2=X2;
  double Best=T2;
  for(long long i=1;i<=X1;i++)
    {
      long long j=(T0-T1)*i/(T2-T0);
      if((T0-T1)*i>(T2-T0)*j)j++;
      if(j<=X2)
        {
          double T=double(i*T1+j*T2)/(i+j);
          if(T<Best+0.000000001){Ans1=i;Ans2=j;Best=T;}
        }
    }
  cout<<Ans1<<' '<<Ans2<<endl;
  return 0;
}