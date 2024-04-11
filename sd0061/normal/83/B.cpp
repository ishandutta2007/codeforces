#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define N 100005
#define LL long long
int n , a[N];
LL k , l , sum;
pair<int , int> p[N];
queue<int> q;
int main()
{
    int i , j , x , y , z;
    cin >> n >> k;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , p[i] = make_pair(a[i] , i) , sum += a[i];
    if (sum < k)
    {
      puts("-1");
      return 0;
    }
    sort(p + 1 , p + n + 1);
    x = 0;
    for (i = 1 ; i <= n ; ++ i)
    {
      if (k >= (LL)(p[i].first - x) * (n - i + 1))
        k -= (LL)(p[i].first - x) * (n - i + 1) , x += p[i].first - x;
      else
      {
        l = k / (n - i + 1);
        k -= l * (n - i + 1) , x += l;
        break;
      }
    }
    for (i = 1 ; i <= n ; ++ i)
    {
      a[i] = a[i] - x;
      if(a[i] > 0)
        q.push(i);
    }
    while (k --)
    {
      x = q.front() , -- a[x] , q.pop();
      if (a[x]) q.push(x);
    }
    while (q.size())
      printf("%d " , q.front()) , q.pop();
    return 0;
}