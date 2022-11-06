//program 99B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  int X,Y;
};

bool operator <(DataType A,DataType B)
{
  return A.X<B.X;
}

int main()
{
  int N;cin>>N;
  DataType A[1000];for(int i=0;i<N;i++){cin>>A[i].X;A[i].Y=i+1;}
  sort(A,A+N);
  bool Flag=!((A[N-1].X-A[0].X)%2);
  for(int i=1;Flag&&i<N-1;i++)Flag=(A[i].X*2==A[0].X+A[N-1].X);
  if(!Flag)cout<<"Unrecoverable configuration."<<endl;
  else if(A[0].X==A[N-1].X)cout<<"Exemplary pages."<<endl;
  else cout<<(A[N-1].X-A[0].X)/2<<" ml. from cup #"<<A[0].Y<<" to cup #"<<A[N-1].Y<<"."<<endl;
  return 0;
}