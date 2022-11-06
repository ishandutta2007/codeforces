//program 105A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Skill
{
  string Name;
  int X;
};

bool operator <(Skill A,Skill B)
{
  return A.Name<B.Name;
}

int main()
{
  int N,M;double K;cin>>N>>M>>K;
  Skill A[40];int Total=0;
  for(int i=0;i<N;i++)
    {
      string Name;int T;cin>>Name>>T;T=int(T*K+0.001);
      if(T>=100)
        {
          A[Total].Name=Name;
          A[Total].X=T;
          Total++;
        }
    }
  for(int i=0;i<M;i++)
    {
      string Name;cin>>Name;
      bool Find=false;
      for(int j=0;!Find&&j<Total;j++)
        if(A[j].Name==Name)
          Find=true;
      if(!Find){A[Total].Name=Name;A[Total].X=0;Total++;}
    }
  sort(A,A+Total);cout<<Total<<endl;
  for(int i=0;i<Total;i++)cout<<A[i].Name<<' '<<A[i].X<<endl;
  return 0;
}