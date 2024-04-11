
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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
char s[N];
int n , a[N];
void work()
{
  int i ;
  scanf("%s" , s);
  for (i = 0 ; s[i] ; i += 2)
    a[n ++] = s[i] - '0';
  sort(a , a + n);
  printf("%d" , a[0]);
  for (i = 1 ; i < n ; ++ i)
    printf("+%d" , a[i]);
}

int main()
{
    work();
  return 0;
}