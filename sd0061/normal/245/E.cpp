#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
string s;
int sum;
int f[N];
int main()
{
  int i , j , l;
  cin >> s;l = s.size();
  for (i = 0 ; i < l ;i ++)
  {
    if (s[i] == '+')
    {
      for (j = 1 ;j <= sum ; j ++)  
        if (f[j] == 1)
        {
          f[j] = 2;
          break;       
        }       
      if (j > sum)
        f[++ sum] = 2;    
    }   
    else
    {
      for (j = 1 ;j <= sum ; j ++)  
        if (f[j] == 2)
        {
          f[j] = 1;
          break;       
        }       
      if (j > sum)
        f[++ sum] = 1;    
    }
  }
  cout << sum << endl;
  return 0;    
}