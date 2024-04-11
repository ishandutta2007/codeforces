#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
long long a , b , c , x , y , z;
int main()
{
  cin >> a >> b >> c;
  x = (long long) sqrt(double(a * b / c));
  y = (long long) sqrt(double(a * c / b));
  z = (long long) sqrt(double(c * b / a));
  
  cout << 4 * (x + y + z) << endl; 
  return 0;    
}