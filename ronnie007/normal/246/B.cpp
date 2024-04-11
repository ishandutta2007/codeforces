#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int n;
int a[100007];

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
  int i;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    }
  sort(a+1,a+n+1);
  }


void solve()
  {
  long long sum=0;
  int mn=99999999;
  int i,j;
  int br=0;
  for(i=1;i<=n;i++)
    {
    sum+=a[i];
    if(mn>a[i])mn=a[i];
    }
  long ost1,ost;
  ost=sum / n;
  ost1=sum % n;

  sum=sum-mn;

  if(ost1==0)printf("%d\n",n);
  else printf("%d\n",n-1);

  }