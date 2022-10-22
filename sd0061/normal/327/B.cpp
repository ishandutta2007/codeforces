#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define N 100003
#define ULL unsigned long long
int n , a[N] , s[N];
bool f[10000001];
void work()
{
  int i , j , k;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
    printf("%d " , 10000000 - (n - i + 1));
}

int main()
{
   //while (~scanf("%d%d",&n,&m))
   work();
   return 0;
}