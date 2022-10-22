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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 1000005
#define LL long long
bool f[N];
char s[10];
int rev(int x)
{
  int y;
  sprintf(s , "%d" , x);
  reverse(s , s + strlen(s));
  sscanf(s , "%d" , &y);
  return y;
}

void work()
{
  int i , j , sum = 0 , n; cin >> n;
  for (i = 2 ; i * i <= 1000000 ; ++ i) if (!f[i])
    for (j = i * i ; j <= 1000000 ; j += i) f[j] = 1;
  f[0] = f[1] = 1;
  for (i = 10 ; i <= 1000000 ; ++ i)
    if (!f[i])
  {
    j = rev(i);
    if (i != j && !f[j])
      ++ sum;
    if (sum == n) break;
  }
  cout << i;
}


int main()
{
  //freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}