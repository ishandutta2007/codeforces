#include<iostream>
#include<stdio.h>
using namespace std;

int n;

void input();
void solve();

int main()
  {
  input();
  solve();
  return 0;
  }


void input()
  {
  scanf("%d",&n);
  }


void solve()
  {
  int i;
  if(n>=3)
    {
    printf("%d %d ",n,n-1);
    for(i=1;i<=n-2;i++)
      {
      printf("%d ",i);
      }
    }
  else printf("-1\n");
  }