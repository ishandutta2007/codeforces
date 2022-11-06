//program 138D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int M,N;
char Map[20][20];
bool Visited[40][40][40][40][2];
int F[40][40][40][40][2];

int Search(int A,int B,int C,int D,int Flag)
{
  if(A>B||C>D)return 0;
  if(Visited[A+19][B+19][C][D][Flag])return F[A+19][B+19][C][D][Flag];
  Visited[A+19][B+19][C][D][Flag]=true;
  set<int> List;
  for(int i=0;i<M;i++)
    for(int j=max(max(i-B,C-i),0);j<=min(min(i-A,D-i),N-1);j++)
      if((i+j+Flag)%2)
        if(Map[i][j]=='L')
          {
            int T=i+j,X1=Search(A,B,C,T-1,Flag),X2=Search(A,B,T+1,D,Flag);
            List.insert(X1^X2);
          }
        else if(Map[i][j]=='R')
          {
            int T=i-j,X1=Search(A,T-1,C,D,Flag),X2=Search(T+1,B,C,D,Flag);
            List.insert(X1^X2);
          }
        else
          {
            int T1=i-j,T2=i+j;
            int X1=Search(A,T1-1,C,T2-1,Flag),X2=Search(A,T1-1,T2+1,D,Flag);
            int X3=Search(T1+1,B,C,T2-1,Flag),X4=Search(T1+1,B,T2+1,D,Flag);
            List.insert(X1^X2^X3^X4);
          }
  int P=0;while(List.count(P))P++;
  return F[A+19][B+19][C][D][Flag]=P;
}

int main()
{
  cin>>M>>N;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      while(Map[i][j]=getchar(),Map[i][j]!='L'&&Map[i][j]!='R'&&Map[i][j]!='X');
  memset(Visited,0,sizeof(Visited));
  cout<<((Search(-(N-1),M-1,0,M+N-2,0)^Search(-(N-1),M-1,0,M+N-2,1))?"WIN":"LOSE")<<endl;
  return 0;
}