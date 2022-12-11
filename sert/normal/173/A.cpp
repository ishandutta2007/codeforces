#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>


using namespace std;

struct shlb
{
  int f, s;
};

int win(char a, char b)
{
  if (a == 'S' && b == 'P') return 1;
  if (a == 'S' && b == 'R') return -1;
  if (a == 'R' && b == 'S') return 1;
  if (a == 'R' && b == 'P') return -1;
  if (a == 'P' && b == 'R') return 1;
  if (a == 'P' && b == 'S') return -1;
  return 0;
}

string s, k;

shlb v[1000001];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, fr = 0, sc = 0;

    cin >> n;
    cin >> s >> k;
    for (int i = 0; i < s.length() * k.length(); i++)
      {
        if (win(s[i % s.length()], k[i % k.length()]) == 1)
        {
          if (i == 0)
          {
            v[i].f = 0;
            v[i].s = 1;
          }
          else
          {
            v[i].f = v[i - 1].f;
            v[i].s = v[i - 1].s + 1;
          }
        }
        else
          if (win(s[i % s.length()], k[i % k.length()]) == -1)
          {
            if (i == 0)
            {
              v[i].f = 1;
              v[i].s = 0;
            }
            else
            {
              v[i].f = v[i - 1].f + 1;
              v[i].s = v[i - 1].s;
            }
          }
          else
          {
            if (i == 0)
            {
              v[i].f = 0;
              v[i].s = 0;
            }
            else
            {
              v[i].f = v[i - 1].f;
              v[i].s = v[i - 1].s;
            }
          }
      }
    int ks = k.length() * s.length();
    fr = ((n - 1) / (ks)) * v[ks - 1].f + v[(n - 1) % ks].f;
    sc = ((n - 1) / (ks)) * v[ks - 1].s + v[(n - 1) % ks].s;
    cout << fr << " " << sc;
    return 0;
}