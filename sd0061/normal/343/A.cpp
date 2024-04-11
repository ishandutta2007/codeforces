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
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1005
LL n , m , ans;

void gcd(LL x , LL y)
{
  if (y)
  {
        ans += x / y;
    gcd(y , x % y);
  }
}

void work()
{
    cin >> n >> m;
    gcd(n , m);
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_--)
        work();
    return 0;
}