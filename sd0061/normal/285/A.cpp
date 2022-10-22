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
#define N 100005
#define M 100005
#define LL long long
int n , a[N];

void work()
{
  int i , x , y , l , r;
  scanf("%d%d",&n,&x);
  for (i = 0 ; i < x; ++ i)
    printf("%d ", n - i);
  for (i = 1 ; i <= n - x; ++ i)
    printf("%d ", i);
}


int main()
{
    work();
  return 0;
}