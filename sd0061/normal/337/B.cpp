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
#define N 200005
int a , b , c , d , x , y , z;


void work()
{
  cin >> a >> b >> c >> d;
  if (a * d <= c * b)
  {
    y = b * c , x = a * d , x = y - x;
    z = __gcd(x , y);
    x /= z , y /= z;
    printf("%d/%d\n" , x , y);
  }
  else
  {
    y = a * d , x = b * c , x = y - x;
    z = __gcd(x , y);
    x /= z , y /= z;
    printf("%d/%d\n" , x , y);
  }
}

int main()
{
 //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}