#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 1005
int n,m,k;
int a[N][N],row[N],line[N];

int main()
{
  int i , j, x ,y; char c;
  cin >> n >> m >> k;
  for (i = 1 ; i <= n ;i ++)
    for (j = 1 ; j <= m ;j ++)
      scanf("%d\n",&a[i][j]);
  for (i = 1 ; i <= n ;i ++)
    row[i] = i;
  for (i = 1 ; i <= m ;i ++)
    line[i] = i;
  while (k --)
  {
    scanf("%c %d %d\n",&c,&x,&y);
    if (c == 'c')
      line[x] ^= line[y] ^= line[x] ^= line[y];
    if (c == 'r')
      row[x] ^= row[y] ^= row[x] ^= row[y];
    if (c == 'g')
      printf("%d\n",a[row[x]][line[y]]);   
  }
  return 0;    
}