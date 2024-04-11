#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int f[301][301];
int main()
{
    cin >>n;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<n;j+=2)f[i][j+1]=j*n+i;
      for(int j=1;j<n;j+=2)f[i][j+1]=j*n+n-i+1;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)printf("%d ",f[i][j]);
      printf("\n");
    }
    return 0;
}