#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , m;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  int i , j, x , y;
  cin >> n >> m;
  if (m > n)
  {
    while (m > n)
      printf("G") , m--;
    while (n && m)
      printf("BG") , n -- , m --;
  }
  else
  {
    while (n > m)
      printf("B") , n--;
    while (n && m)
      printf("GB") , n -- , m --;
  }
  return 0;    
}