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
#define N 10005
using namespace std;
string s;
int n;
void work()
{
  int x = 0 , i;
  cin >> n;
  while (n --)
  {
    cin >> s;
    if (s == "++X") ++ x;
    if (s == "--X") -- x;
    if (s == "X++") ++ x;
    if (s == "X--") -- x;
  }
  cout << x;
}

int main()
{
  //while (~scanf("%s" , s + 1) , s[1] != '*')
  work();
  return 0;
}