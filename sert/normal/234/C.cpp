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

void ret(string s)
{
  cout << s;
  exit(0);
}

string s;
int n, k, kol;
ll ans = N * 2, otr, pol, pos, h;
int a[N], p[N], o[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;


    fr(i, n) cin >> a[i];
    p[0] = 0;
    if (a[0] >= 0) p[0] = 1;
    fab(i, 1, n - 1)
      if (a[i] >= 0) p[i] = p[i - 1] + 1; else p[i] = p[i - 1];
    o[n - 1] = 0;
    if (a[n - 1] <= 0) o[n - 1] = 1;
    fdown(i, n - 1)
      if (a[i] <= 0) o[i] = o[i + 1] + 1; else o[i] = o[i + 1];
    fr(i, n - 1){
      h = p[i] + o[i + 1];
      if (h < ans){
        ans = h;
      }
    }
    cout << ans;


    return 0;
}