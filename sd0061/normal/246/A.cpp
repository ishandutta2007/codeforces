#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n ;

int main()
{
  int i , j;
  cin >> n;
  if (n <= 2)
    cout << -1;
  else
  {
    cout << "2 3 ";
    for (i = 3 ;i <= n ;i ++)
      cout << 1 << ' ';  
  }     
  return 0;    
}