#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005

int x,y,a,b,sum;
int main()
{
  cin >> x >> y >> a >> b;
  for (int i = a ; i <= x ; i ++)
    for (int j = b; j <= y ;j ++)
      if (i > j)
        ++ sum;
  cout << sum << endl;
  for (int i = a ; i <= x ; i ++)
    for (int j = b; j <= y ;j ++)
      if (i > j)
        printf("%d %d\n",i,j);
        
  return 0;    
}