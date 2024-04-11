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
long long ans = 1;
long long Q = 1e9 + 7;

void work()
{
  cin >> n >> k;
  int i;
  for (i = n - k ; i > 0 ; -- i)
    ans *= (n - k) , ans %= Q;
  for (i = k - 1 ; i > 0 ; -- i)
    ans *= k , ans %= Q;
  cout << ans;

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