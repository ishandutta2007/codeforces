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
#define N 100005
char s[N];
int n , a[N] , m;

void work()
{
  int i , j , x , y;
  scanf("%s%d" , s + 1 , &m);
  n = strlen(s + 1);
  for (i = 1 ; i < n ; ++ i)
  {
    a[i] = a[i - 1];
    a[i] += (s[i] == s[i + 1]);
  }
  while (m --)
  {
    scanf("%d%d",&x,&y);
    printf("%d\n" , a[y - 1] - a[x - 1]);
  }
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}