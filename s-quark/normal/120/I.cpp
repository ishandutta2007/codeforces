#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int sp[10] = {0167, 044, 0135, 0155, 056, 0153, 0173, 045, 0177, 0157};
int cnt[128];
int c[10][10];

int a[2<<17];
string s;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  int i, j;
  int tar;
  int sum;
  cin>>s;
  n = s.size()/2;
  for(i = 0; i < n*2; i++)
    a[i] = s[n*2-i-1]-'0';
  for(i = 0; i < 128; i++)
    for(j = 0; j < 7; j++)
      cnt[i] += i>>j&1;
  for(i = 0; i < 10; i++) 
    for(j = 0; j < 10; j++)
      c[i][j] = cnt[sp[i]&sp[j]];
  tar = 0;
  for(i = 0; i < n; i++)
    tar += c[a[i]][a[i+n]];
  sum = tar;
  FOR(i, 0, n*2)
  {
    if(i < n)
    {
      sum -= c[a[i]][a[i+n]];
      for(a[i]++; a[i] < 10; a[i]++)
      {
        sum += c[a[i]][a[i+n]];
        if(sum > tar)
          break;
        sum -= c[a[i]][a[i+n]];
      }
      if(sum > tar)
        break;
      sum += cnt[sp[a[i+n]]];
    }
    else
    {
      sum -= cnt[sp[a[i]]];
      for(a[i]++; a[i] < 10; a[i]++)
      {
        sum += cnt[sp[a[i]]];
        if(sum > tar)
          break;
        sum -= cnt[sp[a[i]]];
      }
      if(sum > tar)
        break;
      sum += 7;
    }
  }
  if(i == n*2)
  {
    printf("-1\n");
    return 0;
  }
  while(i)
  {
    i--;
    if(i < n)
    {
      sum -= cnt[sp[a[i+n]]];
      for(a[i] = 0; a[i] < 10; a[i]++)
      {
        sum += c[a[i]][a[i+n]];
        if(sum > tar)
          break;
        sum -= c[a[i]][a[i+n]];
      }
    }
    else
    {
      sum -= 7;
      for(a[i] = 0; a[i] < 10; a[i]++)
      {
        sum += cnt[sp[a[i]]];
        if(sum > tar)
          break;
        sum -= cnt[sp[a[i]]];
      }
    }
  }
  RFOR(i, n*2, 0)
    printf("%d", a[i]);
  printf("\n");
  return 0;
}