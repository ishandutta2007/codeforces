#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

struct team
{
  string name;
  int gz, gp, score, g;
};

void ret(string s)
{
  cout << s;
  exit(0);
}

bool _less(team a, team b)
{
  if (a.score != b.score) return a.score < b.score;
  if (a.gz - a.gp != b.gz - b.gp) return a.gz - a.gp < b.gz - b.gp;
  if (a.gz != b.gz) return a.gz < b.gz;
  return a.name > b.name;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    team a[4], ber, opp;
    string s, k, h;
    int kol = 0, g1, g2, num, nb;
    bool find;
    fr(i, 5)
    {
      cin >> s >> k >> h;
      g1 = h[0] - '0';
      g2 = h[2] - '0';
      num = -1;
      fr(i, kol)
        if(a[i].name == s)
          num = i;
      if (num == -1)
      {
        a[kol].name = s; a[kol].gp = 0;
        a[kol].gz = 0; a[kol].score = 0;
        a[kol].g = 0;
        kol++;
        num = kol - 1;
      }
      a[num].gz += g1;
      a[num].gp += g2;
      a[num].g++;
      if (g1 > g2) a[num].score += 3;
      if (g1 == g2) a[num].score += 1;


      num = -1;
      fr(i, kol)
        if(a[i].name == k)
          num = i;
      if (num == -1)
      {
        a[kol].name = k; a[kol].gp = 0;
        a[kol].gz = 0; a[kol].score = 0; a[kol].g = 0; kol++;
        num = kol - 1;
      }
      a[num].gz += g2;
      a[num].gp += g1;
      a[num].g++;
      if (g1 < g2) a[num].score += 3;
      if (g1 == g2) a[num].score += 1;
    }
    fr(i, 4)
    {
      if(a[i].name == "BERLAND") nb = i;
      else if(a[i].g == 2) num = i;
    }
    ber = a[nb];
    opp = a[num];
    int r = 1, gb = 0;
    fab(j, 1, 200)
    {
      fr(i, 100)
      {
        r = j;
        gb = i;
        if(gb - r < 0) continue;
        if(r == 0){a[nb].score = ber.score + 1; a[num].score = opp.score + 1;}
        if(r > 0){a[nb].score = ber.score + 3; a[num].score = opp.score;}
        if(r < 0){a[num].score = opp.score + 3; a[nb].score = ber.score;}
        if (r == 3)
          r = r;
        a[nb].gz = ber.gz + gb;
        a[num].gz = opp.gz + gb - r;
        a[nb].gp = ber.gp + gb - r;
        a[num].gp = opp.gp + gb;
        sort(a, a + 4, _less);
        if (a[2].name == "BERLAND" || a[3].name == "BERLAND")
        {
          cout << gb << ":" << gb - r;
          return 0;
        }
        fr(i, 4)
        {
          if(a[i].name == "BERLAND") nb = i;
          else if(a[i].g == 2) num = i;
        }
      }

    }
    cout << "IMPOSSIBLE";
    return 0;
}