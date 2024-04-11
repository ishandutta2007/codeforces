#include<iostream>
#include<stdio.h>
using namespace std;

int main()
  {
  int n;
  int a[5050];
  int used[5050];
  int i;
  int br=0;
  scanf("%d",&n);
  for(i=0;i<5025;i++)
    {
    used[i]=0;
    }
  for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    used[a[i]]=1;
    }
  br=0;
  for(i=1;i<=n;i++)
    {
    if(used[i]==0)br++;
    }
  printf("%d\n",br);
  return 0;
  }