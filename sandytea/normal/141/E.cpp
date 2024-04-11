//program 141E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Total;
int Parent[1000],X[100000],Y[100000];
bool Flag[100000],Must[100000];

void Init(int N)
{
  for(int i=0;i<N;i++)Parent[i]=i;
  Total=N;
}

int Root(int x)
{
  return (Parent[x]==x)?x:(Parent[x]=Root(Parent[x]));
}

bool Union(int p)
{
  int A=Root(X[p]),B=Root(Y[p]);
  if(A!=B){Total--;Parent[A]=B;return true;}
  return false;
}

int main()
{
  int N,M;scanf("%d%d",&N,&M);
  if(N%2==0)
    printf("-1\n");
  else
    {
      for(int i=0;i<M;i++)
        {
          scanf("%d%d",&X[i],&Y[i]);X[i]--;Y[i]--;
          char c=getchar();while(c!='S'&&c!='M')c=getchar();
          Flag[i]=(c=='S');
        }
      Init(N);
      for(int i=0;Total>1&&i<M;i++)Union(i);
      if(Total>1)
        printf("-1");
      else
        {
          Init(N);
          for(int i=0;i<M;i++)if(Flag[i])Union(i);
          memset(Must,0,sizeof(Must));int Count=0;
          for(int i=0;i<M;i++)
            if(!Flag[i])if(Union(i))
              {Must[i]=true;Count++;}
          if(Count>(N-1)/2)
            printf("-1\n");
          else
            {
              Init(N);for(int i=0;i<M;i++)if(Must[i])Union(i);
              for(int i=0;i<M&&Count<(N-1)/2;i++)
                if(!Flag[i])if(Union(i))
                  {Must[i]=true;Count++;}
              if(Count<(N-1)/2)
                printf("-1\n");
              else
                {
                  for(int i=0;i<M;i++)if(Flag[i])Must[i]=Union(i);
                  printf("%d\n",N-1);Count=0;
                  for(int i=0;i<M;i++)
                    if(Must[i])
                      {
                        Count++;printf("%d",i+1);
                        putchar((Count==N-1)?'\n':' ');
                      }
                }
            }
        }
    }
  return 0;
}