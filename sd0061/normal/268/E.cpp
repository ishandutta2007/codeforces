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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

#define N 50005
int n ;
double ans , sum;
struct node
{
  int t , x;
  double p;
  bool operator < (const node& q) const{
    return x * t * (100 - q.x) > q.x * q.t * (100 - x);}
}a[N];

void work()
{
  int i;
  cin >> n;
  for (i = 1 ; i <= n ;i ++)
    scanf("%d%d",&a[i].t,&a[i].x) ,a[i].p = a[i].x / 100.0 , sum += (1.0 - a[i].p) , ans += a[i].t;
  sort(a + 1 , a + n + 1);
  for (i = 1 ; i <= n ;i ++)
  {
    sum -= (1.0 - a[i].p);
    ans += sum * a[i].p * a[i].t;
  }
  printf("%.12lf",ans);
}

int main()
{
  work();
  return 0;
}