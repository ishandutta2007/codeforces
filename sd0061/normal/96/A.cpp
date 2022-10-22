#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 205



void work()
{
  string s;
  cin >> s;
  if (s.find("1111111") != string::npos || s.find("0000000") != string::npos)
    puts("YES");
  else puts("NO");
}

int main()
{
//  freopen("input.txt", "r" , stdin);
    work();
  return 0;
}