//program 141B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int T,X,Y,Ans=-1;scanf("%d%d%d",&T,&X,&Y);
  if(Y>0&&Y<T)
    {if(X*2>-T&&X*2<T)Ans=1;}
  else if(Y>T)
    {
      int t=Y/T,H1=t*T,H2=H1+T;
      if(Y>H1)
        if(t%2)
          {
            if(X*2>-T&&X*2<T)Ans=t/2*3+2;
          }
        else
          {
            if(X>-T&&X<0)Ans=t/2*3;
            if(X>0&&X<T)Ans=t/2*3+1;
          }
    }
  cout<<Ans<<endl;
  return 0;
}