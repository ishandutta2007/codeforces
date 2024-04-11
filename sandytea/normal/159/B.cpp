//program 159B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
  int P,Q;
};

bool operator <(Data A,Data B)
{
  return (A.Q==B.Q)?(A.P<B.P):(A.Q<B.Q);
}

bool operator ==(Data A,Data B)
{
  return (A.P==B.P)&&(A.Q==B.Q);
}

bool operator >(Data A,Data B)
{
  return (A.Q==B.Q)?(A.P>B.P):(A.Q>B.Q);
}

int main()
{
  int M,N;cin>>M>>N;
  Data X[100000],Y[100000];
  for(int i=0;i<M;i++)cin>>X[i].P>>X[i].Q;
  for(int i=0;i<N;i++)cin>>Y[i].P>>Y[i].Q;
  sort(X,X+M);sort(Y,Y+N);
  int Ans_1=0,Ans_2=0,R1=0,R2=0,N1=0,N2=0,A[100000],B[100000];
  while(R1<M&&R2<N)
    if(X[R1]==Y[R2])
      {Ans_1++;Ans_2++;R1++;R2++;}
    else if(X[R1]<Y[R2])
      A[N1++]=X[R1++].Q;
    else if(X[R1]>Y[R2])
      B[N2++]=Y[R2++].Q;
  while(R1<M)A[N1++]=X[R1++].Q;
  while(R2<N)B[N2++]=Y[R2++].Q;
  R1=R2=0;
  while(R1<N1&&R2<N2)
    if(A[R1]==B[R2])
      {Ans_1++;R1++;R2++;}
    else if(A[R1]<B[R2])
      R1++;
    else if(A[R1]>B[R2])
      R2++;
  cout<<Ans_1<<' '<<Ans_2<<endl;
  return 0;
}