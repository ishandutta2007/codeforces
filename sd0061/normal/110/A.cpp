#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define N 2005

void work()
{
  LL n;
  cin >> n;
  int sum = 0;
  while (n)
    sum += (n % 10 == 4 || n % 10 == 7) , n /= 10;
  puts(sum == 4 || sum == 7 ? "YES" : "NO");
}

int main()
{
  work();
  return 0;
}