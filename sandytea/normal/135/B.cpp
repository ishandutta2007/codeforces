//program 135B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int X[8],Y[8],A[8],S[8];
bool Ans,Used[8];

bool Rectangle(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4)
{
  if(X1+X3!=X2+X4)return false;
  if(Y1+Y3!=Y2+Y4)return false;
  if((X1-X3)*(X1-X3)+(Y1-Y3)*(Y1-Y3)!=(X2-X4)*(X2-X4)+(Y2-Y4)*(Y2-Y4))return false;
  return true;
}

bool Square(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4)
{
  return ((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)==(X2-X3)*(X2-X3)+(Y2-Y3)*(Y2-Y3));
}

bool Check()
{
  if(Rectangle(X[A[0]],Y[A[0]],X[A[1]],Y[A[1]],X[A[2]],Y[A[2]],X[A[3]],Y[A[3]]))
    if(Square(X[A[0]],Y[A[0]],X[A[1]],Y[A[1]],X[A[2]],Y[A[2]],X[A[3]],Y[A[3]]))
      if(Rectangle(X[A[4]],Y[A[4]],X[A[5]],Y[A[5]],X[A[6]],Y[A[6]],X[A[7]],Y[A[7]]))
        return true;
  return false;
}

void DFS(int Depth)
{
  if(Ans)return;
  if(Depth==8)
    {
      if(Check())
        {
          Ans=true;
          for(int i=0;i<8;i++)S[i]=A[i]+1;
        }
      return;
    }
  for(int i=0;i<8;i++)
    if(!Used[i])
      {
        Used[i]=true;
        A[Depth]=i;
        DFS(Depth+1);
        Used[i]=false;
      }
}

int main()
{
  for(int i=0;i<8;i++)cin>>X[i]>>Y[i];
  Ans=false;memset(Used,0,sizeof(Used));
  DFS(0);
  if(Ans)
    printf("YES\n%d %d %d %d\n%d %d %d %d\n",S[0],S[1],S[2],S[3],S[4],S[5],S[6],S[7]);
  else
    printf("NO\n");
  return 0;
}