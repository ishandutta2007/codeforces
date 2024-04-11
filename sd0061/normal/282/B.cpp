#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 1000005
using namespace std;

void work()
{
    int n, now=0, num;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d%*d", &num);
        now+=num;
    }
    while( now>500 ) now-=1000, n--, putchar('G');
    while( n-- ) putchar('A');
    putchar('\n');
}

int main()
{
  //while (~scanf("%s" , s + 1) , s[1] != '*')
  work();
  return 0;
}