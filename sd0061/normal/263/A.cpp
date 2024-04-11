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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
int ans;
void work()
{
  int x;
  for (int i = 0 ; i < 25 ; ++ i)
    scanf("%d",&x) , ans = max(ans , x * ( abs(i/5 - 2) + abs(i%5 - 2)));
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}