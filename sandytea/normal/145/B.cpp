//program 145B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int A,B,C,D;cin>>A>>B>>C>>D;
  bool Ans=false;
  if(C==D+1&&A>D&&B>D)
    {
      for(int i=0;i<A-D;i++)putchar('4');
      for(int i=0;i<D;i++){putchar('7');putchar('4');}
      for(int i=0;i<B-D;i++)putchar('7');
      putchar('\n');Ans=true;
    }
  if(C==D-1&&A>C&&B>C)
    {
      putchar('7');
      for(int i=0;i<A-C;i++)putchar('4');
      for(int i=0;i<C-1;i++){putchar('7');putchar('4');}
      for(int i=0;i<B-C;i++)putchar('7');
      putchar('4');
      putchar('\n');Ans=true;
    }
  if(C==D)
    if(A>C&&B>=C)
      {
        D--;
        for(int i=0;i<A-C;i++)putchar('4');
        for(int i=0;i<D;i++){putchar('7');putchar('4');}
        for(int i=0;i<B-D;i++)putchar('7');
        putchar('4');
        putchar('\n');Ans=true;
      }
    else if(A>=C&&B>C)
      {
        C--;
        putchar('7');
        for(int i=0;i<A-C;i++)putchar('4');
        for(int i=0;i<C;i++){putchar('7');putchar('4');}
        for(int i=0;i<B-D;i++)putchar('7');
        putchar('\n');Ans=true;
      }
  if(!Ans)cout<<-1<<endl;
  return 0;
}