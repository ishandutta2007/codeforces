#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 135
#define M 65
int n , a[N][N] , m , b[N][N];
int p[2];
void work()
{
  cin >> n >> m;
  a[M][M] = n;
  int i , j , x , y;

  while (1)
  {
    y = 0;
    memset(b , 0 , sizeof(b));
    for (i = -M ; i <= M ; ++ i)
      for (j = -M ; j <= M ; ++ j) if (a[i + M][j + M] >= 4)
      {
        x = a[i + M][j + M] >> 2 , b[i + M][j + M] += a[i + M][j + M] & 3;
        b[i + M - 1][j + M] += x , b[i + M + 1][j + M] += x;
        b[i + M][j + M - 1] += x , b[i + M][j + M + 1] += x;
        y = 1;
      }
      else b[i + M][j + M] += a[i + M][j + M] & 3;

    if (!y) break;
      memcpy(a , b , sizeof(b));
  }
  while (m --)
  {
    scanf("%d%d",&x,&y);
    if (abs(x) <= M && abs(y) <= M)
      printf("%d\n" , a[x + M][y + M]) ;
    else printf("0\n");
  }

}

int main()
{
  work();
  return 0;
}