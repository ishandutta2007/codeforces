#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , a , b;

int main()
{
  int i ,  x , y;
  cin >> n ;
  for (i = 1 ;i <= n ;i ++)
  {
    cin >> x >> y;
    if (x) a ++;
    if (y) b ++;  
  }
  cout << min(a,n-a) + min(b,n-b) << endl;     
  return 0;    
}