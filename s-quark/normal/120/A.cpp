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


int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string s;
  int a;
  cin>>s>>a;
  if((s == string("front")) ^ (a==1))
    printf("R\n");
  else
    printf("L\n");
  return 0;
}