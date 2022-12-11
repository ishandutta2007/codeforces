#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 1e6;
const ll M = 1e6;

using namespace std;

struct film{
  string name;
  int mx, mn;
};

void ret(string s)
{
  cout << s;
  exit(0);
}

film f[200];
int a[200], b[200], n, m, k, kl, kla, knla, h, kn;
int mx = -1, mn = -1;
bool u[200];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> m >> k;
    fr(i, k) cin >> a[i];
    fr(i, k) u[a[i]] = true;
    cin >> n;
    fr(i, n){
      cin >> f[i].name;
      cin >> kl;
      kla = 0;
      knla = 0;
      kn = 0;
      fr(j, kl){
        cin >> h;
        if (h > 0)
          if (u[h] == true) kla++;
          else knla++;
        else
          kn++;
      }
      f[i].mn = max(kla, kl - (m - k));
      f[i].mx = min(kla + kn, k);
      mn = max(f[i].mn, mn);
      mx = max(f[i].mx, mx);
      //cerr << mn << " " << mx << "\n";
    }
    bool bst;
    fr(i, n){
      bst = true;
      fr(j, n){
        if (i != j && f[j].mx > f[i].mn)
          bst = false;
      }
      if (bst == true) cout << "0\n";
      else if (f[i].mx < mn) cout << "1\n";
      else cout << "2\n";
    }
    return 0;
}