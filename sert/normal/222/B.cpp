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

int px[N], py[N];
int a[1000][1000], n, m, k, h, x, y;
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    fr(i, n) px[i] = i;
    fr(i, m) py[i] = i;
    fr(i, n)
      fr(j, m)
        cin >> a[i][j];
    fr(i, k){
      cin >> s;
      cin >> x >> y;
      x--;
      y--;
      if (s == "g")
        cout << a[px[x]][py[y]] << "\n";
      if (s == "r")
        swap(px[x], px[y]);
      if (s == "c")
        swap(py[x], py[y]);
    }
    return 0;
}