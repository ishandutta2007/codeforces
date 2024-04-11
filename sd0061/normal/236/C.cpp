#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

long long n , ma ,mb ,mc;
long long ans, mul;
long long gcd(long long x ,long long y) {return x % y == 0 ? y : gcd(y , x % y);}

int main()
{
  long long i , j , k;  
  cin >> n;
  if (n % 6 == 0) n --;
  if (n <= 2)
  {
    cout << n << endl;
    return 0;    
  }
  
  for (i = n ; i >= 1 ; -- i)
    for (j = i - 1; j >= 1 ;  -- j)
      if (gcd(i ,j) == 1)
      {
        for (k = j - 1; k >= 1 ; -- k)
          if (gcd(i ,k) == 1 && gcd (j , k) == 1)
          {
            cout << i * j * k << endl;
            return 0;      
          }
      }
}