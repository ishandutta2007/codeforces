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
#define N 105
#define LL long long
string s;
void work()
{
  cin >> s;
  char c = s[s.size() - 1];
  s.erase(s.size() - 1 , 1);
  s.replace(s.find("at" , 1) , 2 , "@");
  int i = 1;
  while( (i = s.find("dot", i)) != string::npos )
    s.replace(i, 3, ".");
  cout << s + c;
}

int main()
{
  work();
  return 0;
}