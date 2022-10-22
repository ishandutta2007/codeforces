#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int n , a[3] , x;
int main()
{
  scanf("%d",&n);
  for (int i = 0 ;i < n ;i ++)
    scanf("%d",&x) , a[i % 3] += x;
  if (a[0] > a[1] && a[0] > a[2]) cout << "chest";  
  if (a[1] > a[0] && a[1] > a[2]) cout << "biceps";  
  if (a[2] > a[1] && a[2] > a[0]) cout << "back";  
  return 0;    
}