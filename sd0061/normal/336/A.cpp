#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 10005
int n;
int a , b;
void work()
{
  cin >> a >> b;
  if (a > 0 && b > 0)
    printf("%d %d %d %d\n" , 0 , a + b , a + b , 0);
  if (a < 0 && b > 0)
    printf("%d %d %d %d\n" , a - b , 0 , 0 , b - a);
  if (a < 0 && b < 0)
    printf("%d %d %d %d\n" , a + b , 0 , 0 , a + b);
  if (a > 0 && b < 0)
    printf("%d %d %d %d\n" , 0 , b - a , a - b , 0);
}

int main()
{
     //  freopen("~output.txt","w",stdout);
  //init();
 // int _; scanf("%d",&_); while (_--)
    work();
  return 0;
}