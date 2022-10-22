#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 2000005
#define LL long long
int n , a[N];

void work()
{
  int i , j , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    a[i] = i;
  int top = 1 , bot = n;
  for (i = 2 ; i <= n ;i ++)
  {
    y = n % i , x = n / i , ++ bot;
    a[bot] = a[bot - y];
    for (j = top + x * i ; j >= top ; j -= i)
      a[j] = a[j - i];
    ++ top;
  }
  for (i = top ; i <= bot ;i ++)
    printf("%d ", a[i]);
}

int main()
{
    work();
  return 0;
}