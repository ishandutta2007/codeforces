//program 144B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int X[1000],Y[1000],R[1000];

bool Check(int P,int Q)
{
  for(int i=0;i<N;i++)
    if((P-X[i])*(P-X[i])+(Q-Y[i])*(Q-Y[i])<=R[i]*R[i])
      return false;
  return true;
}

int main()
{
  int A,B,C,D,X1,Y1,X2,Y2;cin>>A>>B>>C>>D;
  X1=min(A,C);Y1=min(B,D);X2=max(A,C);Y2=max(B,D);
  cin>>N;for(int i=0;i<N;i++)cin>>X[i]>>Y[i]>>R[i];
  int Ans=0;
  for(int i=Y1;i<=Y2;i++){if(Check(X1,i))Ans++;if(Check(X2,i))Ans++;}
  for(int i=X1+1;i<X2;i++){if(Check(i,Y1))Ans++;if(Check(i,Y2))Ans++;}
  cout<<Ans<<endl;
  return 0;
}