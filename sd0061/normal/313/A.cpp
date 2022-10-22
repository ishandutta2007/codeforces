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
#define N 1005
char s[N];

void work()
{
  int n , x , y , l;
  scanf("%d",&n);
  sprintf(s , "%d" , n);
  l = strlen(s);
  y = s[l - 1];
  s[l - 1] = 0;
  sscanf(s , "%d" , &x);
  s[l - 2] = y;
  sscanf(s , "%d" , &y);
  cout << max(n , max(x , y)) << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}