#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

vector <int> es[300000];
vector <bool> in[300000];
int s[300000], f[300000], ans[300000], len = 0, tme = 0, bst = 0, lbs = 0;
bool u[300000];

void ret(string s)
{
  cout << s;
  exit(0);
}

void dfs(int v, int lv)
{
  cerr << v << " " << lv << "\n";
  int w;
  if (lv == lbs)
  {
    ans[len] = v;
    len++;
  }

  if (lv > lbs)
  {
    lbs = lv;
    bst = v;
    len = 1;
    ans[0] = v;
  }

  u[v] = true;
  fr(i, (int)es[v].size()){
    if (!in[v][i] && !u[es[v][i]])
      dfs(es[v][i], lv + 1);
    if (in[v][i] && !u[es[v][i]])
      dfs(es[v][i], lv - 1);
  }
  //lv--;
}

int dfs_check(int v)
{
  u[v] = true;
  int ans = 0;
  fr(i, (int)es[v].size())
    if (!u[es[v][i]])
    {
      ans += dfs_check(es[v][i]);
      if (!in[v][i]) ans++;
    }
  return ans;
}

int v, w, n;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n - 1)
    {
      cin >> v >> w;
      es[v - 1].push_back(w - 1);
      es[w - 1].push_back(v - 1);
      in[v - 1].push_back(true);
      in[w - 1].push_back(false);
    }
    dfs(0, 0);
    fr(i, n) u[i] = false;
    cout << dfs_check(bst) << "\n";
    sort(ans, ans + len);
    fr(i, len) cout << ans[i] + 1 << " ";
    return 0;
}