#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
int n,k;
int a[N];

int main()
{
  int i;
  cin >> n >> k;
  for (i = 1 ; i <= n ;i ++)
    cin >> a[i];
  int x = a[k];
  for (i = k + 1 ; i <= n ; i ++)
    if (a[i] != x)
      break;
  if (i <= n)      
    cout << -1 << endl;
  else 
  {
    for (i = 1 ; k - i > 0 ; i ++)
      if (a[k - i] != x)
        break;      
    cout << k - i << endl;
  }
  return 0;    
}