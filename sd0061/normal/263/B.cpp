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
int n , k , a[N];
void work()
{
  int i ;
  cin >> n >> k;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i];
  sort(a , a + n);
  if (k > n)
    cout << -1 << endl;
  else printf("%d %d\n",a[n - k],0);
}

int main()
{
  work();
  return 0;
}