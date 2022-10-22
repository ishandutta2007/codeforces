#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int a ,b , c ,d ,n , ans;
int main()
{
  cin >> a >> b >> c >> d >> n;
  for (int i = 1 ; i <= n ;i ++)
    if (i % a && i % b && i % c && i % d)
      ans ++;
  cout << n - ans;    
  return 0;
}