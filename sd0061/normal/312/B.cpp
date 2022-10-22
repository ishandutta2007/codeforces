#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 3
using namespace std;
typedef long long LL;
int n , m;


void work()
{
  int a , b , c , d;
  cin >> a >> b >> c >> d;
  double p = 1. * a / b , q = 1. * c / d;
  printf("%lf" , p / (p + q - p * q));
}

int main()
{
  //int _;cin >> _; while (_--)
  //while (scanf("%d",&n) , n)
    work();
  return 0;
}