//program 134C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct DataType
{
  int V,X;
};

bool operator<(DataType A,DataType B)
{
  return A.X<B.X;
}

int X[100000],Y[100000];
DataType Stack[200000];

int main()
{
  int N,M;cin>>N>>M;
  priority_queue<DataType> List;
  for(int i=0;i<N;i++)
    {
      int X;scanf("%d",&X);
      if(X){DataType T;T.V=i+1;T.X=X;List.push(T);}
    }
  bool Right=true;int Total=0;
  while(Right&&!List.empty())
    {
      DataType T=List.top();List.pop();
      if(List.size()<T.X)
        Right=false;
      else
        {
          int Count=0;
          for(int i=0;i<T.X;i++)
            {
              DataType Q=List.top();List.pop();
              X[Total]=T.V;Y[Total]=Q.V;Total++;
              if(--Q.X)Stack[Count++]=Q;
            }
          for(int i=0;i<Count;i++)List.push(Stack[i]);
        }
    }
  if(!Right)
    cout<<"No"<<endl;
  else
    {
      printf("Yes\n%d\n",Total);
      for(int i=0;i<Total;i++)printf("%d %d\n",X[i],Y[i]);
    }
}