//program 157B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const double pi=3.141592653589793;

int main()
{
  int N;cin>>N;
  int R[100];for(int i=0;i<N;i++)cin>>R[i];
  sort(R,R+N);
  bool Flag=true;
  double Ans=0;
  for(int i=N-1;i>=0;i--,Flag=!Flag)
    if(Flag)Ans+=R[i]*R[i];else Ans-=R[i]*R[i];
  printf("%0.10lf\n",Ans*pi);
  return 0;
}