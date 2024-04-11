//program 93B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const double eps=1e-6;

struct Data
{
  int X;
  double Y;
};

int main()
{
  int N,M;double V;cin>>N>>V>>M;
  vector<Data> List[50];
  double Current=0;bool Flag=true;
  for(int i=1,j=0;Flag&&i<=N;i++)
    {
      double T=V;int Count=0;
      while(T>eps)
        {
          double Tmp=min(T,N*V/M-Current);
          List[j].push_back((Data){i,Tmp});
          T-=Tmp;Current+=Tmp;if(Current+eps>N*V/M){Current=0;j++;}
          Count++;
        }
      if(Count>2)Flag=false;
    }
  if(!Flag)
    cout<<"NO"<<endl;
  else
    {
      cout<<"YES"<<endl;
      for(int i=0;i<M;i++)
        for(int j=0;j<List[i].size();j++)
          {
            cout<<List[i][j].X<<' ';
            printf("%0.10lf",List[i][j].Y);
            putchar((j==List[i].size()-1)?'\n':' ');
          }
    }
  return 0;
}