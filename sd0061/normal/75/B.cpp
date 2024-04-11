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

string name;
map<string , int> hash;
int tot;
struct node
{
  string str;
  int score;
  bool operator < (const node& r) const{
    if (score == r.score)
      return str < r.str;
    return score > r.score;
  }
}a[N];


void work()
{
  int n;
  string s , t , p;
  cin >> name >> n;
  hash[name] = -1;
  while (n --)
  {
    cin >> s >> t;
    if (!hash.count(s))
      hash[s] = tot , a[tot ++].str = s;
    if (t[0] == 'p')
    {
      cin >> t; cin >> t;
      t.erase(t.size() - 2 , 2); cin >> p;
      if (!hash.count(t))
        hash[t] = tot , a[tot ++].str = t;
      if (t == name) swap(s , t);
      if (s != name || t == name) continue;
      a[hash[t]].score += 15;
    }
    else if (t[0] == 'c')
    {
      cin >> t; cin >> t;;
      t.erase(t.size() - 2 , 2); cin >> p;
      if (!hash.count(t))
        hash[t] = tot , a[tot ++].str = t;
      if (t == name) swap(s , t);
      if (s != name || t == name) continue;
      a[hash[t]].score += 10;
    }
    else if (t[0] == 'l')
    {
      cin >> t;
      t.erase(t.size() - 2 , 2); cin >> p;
      if (!hash.count(t))
        hash[t] = tot , a[tot ++].str = t;
      if (t == name) swap(s , t);
      if (s != name || t == name) continue;
      a[hash[t]].score += 5;
    }
  }
  sort(a , a + tot);
  for (int i = 0 ; i < tot ; ++ i)
    cout << a[i].str << endl;
}

int main()
{
  work();
  return 0;
}