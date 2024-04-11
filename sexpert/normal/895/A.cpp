#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  {
      cin >> a[i];
  }
  int minDiff = 360;
  int sum;
  for(int i = 0; i < n; i++)
  {
      sum = 0;
      for(int j = i; j < n; j++)
      {
          sum += a[j];
          int diff = 2*abs(sum - 180);
          if(diff < minDiff)
          {
              minDiff = diff;
          }
      }
  }
  cout << minDiff;
}