//program 92D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int A[100000];for(int i=0;i<N;i++)cin>>A[i];
  int Data[100000];for(int i=0;i<N;i++)Data[i]=A[i];
  sort(Data,Data+N);
  for(int i=0;i<N;i++)
    {
      int Left=0,Right=N-1;
      while(true)
        {
          int Mid=(Left+Right)/2;
          if(Data[Mid]==A[i]){A[i]=Mid;break;}
          if(Data[Mid]<A[i])Left=Mid+1;else Right=Mid-1;
        }
    }
  int Tree[100001],Ans[100000];memset(Tree,0,sizeof(Tree));
  for(int i=N-1;i>=0;i--)
    {
      int T,Max=0;
      T=A[i];while(T){Max=max(Max,Tree[T]);T^=T&(-T);}
      Ans[i]=max(Max-i,0)-1;
      T=A[i]+1;while(T<=N){Tree[T]=max(Tree[T],i);T+=T&(-T);}
    }
  for(int i=0;i<N;i++)cout<<Ans[i]<<((i==N-1)?'\n':' ');
  return 0;
}