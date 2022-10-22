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
#define N 100005
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}
int n , a[N] , k;
char s[N * 10];
void work()
{
  cin >> n >> k;
  int i;
  if (k == 1)
  {
    if (n == 1)
      putchar('a');
    else puts("-1");
    return;
  }
  if (k > n)
  {
    puts("-1");
    return;
  }
  if (k == 1)
  {
    for (i = 1 ; i <= n ; ++ i)
      putchar('a');
    return;
  }

  while (n > k)
  {
    printf("ab");
    n -= 2;
  }
  if (k == 2)
  {
    if (n == 2)
      printf("ab");
    else printf("a");
    return;
  }
  if (n == k)
    for (i = 'a' ; i < 'a' + k ; ++ i)
      putchar(i);
  else
  {
    printf("a"); -- n;
    for (i = 'c' ; i < 'c' + n ; ++ i)
      putchar(i);
  }

}

int main()
{
 // freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while(~scanf("%d%d%d",&n,&L,&R))
    work();
  return 0;
}