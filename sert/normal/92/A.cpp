#include <iostream>
#include <stdio.h>

using namespace std;

int main ()
{
 long int x, n, i, j=0;
 cin >> x >> n;
 while (1 <= 1)
 {
     j++;
     if (j > x) j = 1;
     if (n < j){cout << n; return 0;}
     n = n - j;
 }
 return 0;
}