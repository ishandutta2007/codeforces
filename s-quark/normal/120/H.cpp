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

int num[256];
int a[256][10000];
int mat[531441];
int mat2[256];
int qu[256], pre[256];
string s[256];
int t[4];

int code(int *s)
{
  int t, i;
  t = 0;
  for(i = 0; i < 4; i++)
  {
    t *= 27;
    t += s[i];
  }
  return t;
}

string decode(int t)
{
  string s;
  while(t)
  {
    s.pb((char)(t%27+'a'-1));
    for(int i = s.size()-1; i > 0; i--)
      swap(s[i], s[i-1]);
    t /= 27;
  }
  while(s[s.size()-1] == 'a'-1)
    s = s.substr(0, s.size()-1);
  return s;
}

void no()
{
  printf("-1\n");
  exit(0);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  int i, j, k;
  int i0, i1, i2, i3;
  cin>>n;
  t[0] = t[1] = t[2] = t[3] = 0;
  memset(num, 0, sizeof num);
  for(i = 0; i < n; i++)
  {
    cin>>s[i];
    m = s[i].size();
    FOR(i0, 0, m)
    {
      t[0] = s[i][i0] - 'a' + 1;
      FOR(i1, i0+1, m)
      {
        t[1] = s[i][i1] - 'a' + 1;
        FOR(i2, i1+1, m)
        {
          t[2] = s[i][i2] - 'a' + 1;
          FOR(i3, i2+1, m)
          {
            t[3] = s[i][i3] - 'a' + 1;
            a[i][num[i]++] = code(t);
          }
          t[3] = 0;
          a[i][num[i]++] = code(t);
        }
        t[2] = 0;
        a[i][num[i]++] = code(t);
      }
      t[1] = 0;
      a[i][num[i]++] = code(t);
    }
    t[0] = 0;
  }
  memset(mat, -1, sizeof mat);
  for(i = 0; i < n; i++)
  {
    int h, t;
    h = t = 0;
    memset(pre, -1, sizeof(pre));
    pre[i] = -2;
    qu[t++] = i;
    while(h < t)
    {
      j = qu[h++];
      for(k = 0; k < num[j]; k++)
      {
        if(mat[a[j][k]] == -1)
          break;
        if(pre[mat[a[j][k]]] == -1)
        {
          pre[mat[a[j][k]]] = j;
          qu[t++] = mat[a[j][k]];
        }
      }
      if(k < num[j])
        break;
    }
    if(k == num[j])
      no();
    k = a[j][k];
    mat[k] = j;
    while(j != i)
    {
      swap(k, mat2[j]);
      j = pre[j];
      mat[k] = j;
    }
    mat2[i] = k;
  }
  for(i = 0; i < n; i++)
  {
    cout<<decode(mat2[i])<<endl;
  }
  return 0;
}