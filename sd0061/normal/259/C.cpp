#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
char s[N]; int n ;
int main()
{
  int i , j , x;
  scanf("%s",s) , n = strlen(s);
  for (i = 0 ;i < n ;i ++)
    if (s[i] == '0')
      break;
  if (i >= n)
    i = 0;    
  for (j = 0 ; j < n ;j ++)
    if (j != i)
      printf("%c",s[j]);      
  
  return 0;    
}