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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 15


void work()
{
  int n , i , j , x , y;
  cin >> n;
  x = 1 , y = n * n;
  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = 0 ; j < n ; j += 2)
      printf("%d %d " , x ++ , y --);
    puts("");
  }
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}