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
int n ;
char a[N];
int st[N] , top;
void work()
{
    int i;
    scanf("%s" , a);
    for (i = 0 ; a[i] ; ++ i)
    {
      st[top ++] = (a[i] == '+') + 1;
      while (top > 1 && st[top - 1] == st[top - 2]) top -= 2;
    }
    puts(top ? "No" : "Yes");
}

int main()
{
    work();
    return 0;
}