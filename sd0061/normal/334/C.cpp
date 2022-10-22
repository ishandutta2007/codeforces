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
  LL n , p = 1;
  cin >> n;
  while ( n % p == 0)
    p *= 3;
  cout << (n + p - 1) / p;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}