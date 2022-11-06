//program 93C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct op
{
  int X,Y,Z;
};

const int inf=1000000000;

int Ans;
vector<int> List;
stack<op> Stack,Best;

void Out(int X)
{
  putchar('e');putchar(X+97);putchar('x');
}

void DFS(int Depth,int Max,int N)
{
  if(Depth>Ans)return;
  if(Max==N){Ans=Depth-1;Best=Stack;return;}
  vector<int> TList=List;
  for(int i=0;i<4;i++)
    for(int j=0;j<List.size();j++)
      {
        int T=List[j]<<i;
        if(T>Max&&T<=N)
          {
            List.push_back(T);Stack.push((op){1<<i,j,-1});
            DFS(Depth+1,T,N);
            List=TList;Stack.pop();
          }
      }
  for(int i=0;i<4;i++)
    for(int j=0;j<List.size();j++)
      for(int k=0;k<List.size();k++)
        {
          int T=(List[j]<<i)+List[k];
          if(T>Max&&T<=N)
            {
              List.push_back(T);Stack.push((op){1<<i,j,k});
              DFS(Depth+1,T,N);
              List=TList;Stack.pop();
            }
        }
}

int main()
{
  int N;cin>>N;
  List.push_back(1);
  Ans=6;DFS(1,1,N);
  cout<<Ans<<endl;
  int T=Ans;op A[100];while(T--){A[T]=Best.top();Best.pop();}
  for(int i=0;i<Ans;i++)
    {
      cout<<"lea ";Out(i+1);cout<<", [";
      if(A[i].Z!=-1){Out(A[i].Z);cout<<" + ";}
      cout<<A[i].X<<'*';Out(A[i].Y);cout<<"]"<<endl;
    }
  return 0;
}