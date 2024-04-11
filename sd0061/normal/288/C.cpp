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
#define N 1000005
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}
int n ;
int a[N];
void work()
{

  cin >> n; int m = n;
  cout << (long long) n * (n + 1) << endl;
  int i = 0;
    while (i < n)
      i = i << 1 | 1;
      int j = n;
  while (i)
  {
    for (j = i ^ n ; j <= n ; ++ j)
      a[j] = j ^ i;
    n = (i ^ n) - 1;
    i = 0;
    while (i < n)
      i = i << 1 | 1;
  }
  for (i = 0 ; i <= m ; ++ i)
    printf("%d " , a[i]);
}

int main()
{
 // freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while(~scanf("%d%d%d",&n,&L,&R))
  //for (n = 1 ; n <= 15 ; ++ n)
    work();
  return 0;
}