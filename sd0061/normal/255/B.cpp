#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
char c ; int sx , sy;
int main()
{
  while ((c = getchar()) != EOF)
  {
    if (c == 'x') sx ++;
    if (c == 'y') sy ++;
  }
  if (sx > sy)
    for (int i = 1 ; i <= sx - sy ; i ++)
      putchar('x');
  else     
    for (int i = 1 ; i <= sy - sx ; i ++)
      putchar('y');
  return 0;    
}