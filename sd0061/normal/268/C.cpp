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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

#define N 40005
int n , m;
set<int> h;

void work()
{
  int i , x;
  cin >> n >> m;
  x = min(n,m);
  printf("%d\n" , x + 1);
  for (int i = 0 ; i <= x ; ++i)
    printf("%d %d\n" , x - i , i);
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  work();
  return 0;
}