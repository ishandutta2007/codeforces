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

string s, s1, s2;
int aq[N], bq[N];
bool u[N];
int n, m, k, l, r, t, q, x, y, a, b, len = 0;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int mn = N * 2000;
    int mx = -mn;
    fr(i, n){
      cin >> aq[i];
      cin >> bq[i];
      mn = min(mn, aq[i]);
      mx = max(mx, bq[i]);
    }

    fr(i, n){
      if (aq[i] == mn && bq[i] == mx){
        cout << i + 1;
        return 0;
      }
    }
    cout << "-1";
    return 0;
}