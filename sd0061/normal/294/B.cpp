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
#define N 105
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

int n ;
pair<int ,int> a[N];
int f[N][N << 1];

void work()
{
  int i , j , sum = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d" , &a[i].fi , &a[i].se) , sum += a[i].fi;
  for (j = 1 ; j <= sum ; ++ j)
    f[0][j] = 1 << 30;
  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = 0 ; j < a[i].fi ; ++ j) f[i][j] = f[i - 1][j] + a[i].se;
    for (j = a[i].fi ; j <= sum ; ++ j)
      f[i][j] = min(f[i - 1][j - a[i].fi] , f[i - 1][j] + a[i].se);
  }
  int ans = 1 << 30;
  for (j = 1 ; j <= sum ; ++ j)
    if (j >= f[n][j])
      ans = min(j , ans);
  cout << ans;
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