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

int n, kol = 0, h = 1, r;
int a[N], len = 0;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    int k = 1;
    while (k < n) {k *= 2; kol++;}
    cout << kol << "\n";
    //cerr << k;
    fr(i, kol){
      h *= 2;
      r = k / h;
      //cerr << r;
      len = 0;
      fr(j, n)
        if ((j / r) % 2 == 0)
          a[len++] = j;
      cout << len;
      fr(j, len) cout << " " << a[j] + 1;
      cout << "\n";
    }

    return 0;
}