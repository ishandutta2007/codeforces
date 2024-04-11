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

int n , a[N] , m;
void work()
{
  int i , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  scanf("%d",&m);
  while (m --)
  {
    scanf("%d%d",&x,&y);
    a[x - 1] += y - 1;
    a[x + 1] += a[x] - y;
    a[x] = 0;
  }
  for (i = 1 ; i <= n ; ++ i)
    printf("%d\n" , a[i]);
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while (scanf("%s" , s) , s[0] != '#')
    work();
  return 0;
}