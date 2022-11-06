//program 158B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int C1=0,C2=0,C3=0,C4=0;
  for(int i=0;i<N;i++)
    {
      int X;cin>>X;
      if(X==1)C1++;
      if(X==2)C2++;
      if(X==3)C3++;
      if(X==4)C4++;
    }
  int Ans=C3+C4+C2/2;
  if(C1>C3)C1-=C3;else C1=0;
  if(C2&1)C1+=2;
  if(C1)Ans+=(C1-1)/4+1;
  cout<<Ans<<endl;
  return 0;
}