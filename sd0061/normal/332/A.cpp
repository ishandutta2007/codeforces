#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 100005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n ;
char s[N];

void work()
{
  int i , j , ans = 0 , l;
  cin >> n >> s + 1 , l = strlen(s + 1);
  for (i = 1 ; i <= l ; i += n)
    if (i > 4)
    {
      if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3])
        ++ ans;
    }
  cout << ans << endl;
}

int main()
{
  //int _; scanf("%d",&_); while(_--)
  //while (scanf("%d",&n) , n)
    work();
  return 0;
}