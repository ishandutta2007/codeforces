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
#define N 100005
int n , m ;
int a[N] , b[N];
vector<int> ans;
list<int> A , B;

void work()
{
  cin >> n >> m;
  if (m >= (n * (n - 1) / 2))
    puts("no solution");
  else for (int i = 0 ; i < n ; ++ i)
    printf("%d %d\n" , 0 , i);
}

int main()
{
  std::ios::sync_with_stdio(false);
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}