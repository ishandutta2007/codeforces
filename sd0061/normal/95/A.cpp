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
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

#define LL long long
string str , s[100];
char c;
int n , f[105];

string TOLOWER(string p)
{
  for (int i = 0 ; i < p.size() ; ++ i)
    p[i] = tolower(p[i]);
  return p;
}

void work()
{
  int i , j;
  cin >> n;
  for (i = 0 ;i < n ; ++ i)
    cin >> s[i];
  cin >> str >> c;
  for (i = 0 ; i < str.size() ; ++ i)
    for (j = 0 ;j < n ; ++ j)
      if (TOLOWER(s[j]) == TOLOWER(str.substr(i , s[j].size())))
        ++ f[i] , -- f[i + s[j].size()];
  for (i = 0 ; i < str.size() ; ++ i)
    f[i + 1] += f[i];
  for (i = 0 ; i < str.size() ; ++ i)
    if (f[i])
    {
      char cc = tolower(str[i]);
      if(cc != c)
        cc = c;
      else
      {
        if (cc == 'a')
          cc = 'b';
        else cc = 'a';
      }
      str[i] = isupper(str[i]) ? toupper(cc) : cc;
    }
  cout << str;
}


int main()
{
    work();
  return 0;
}