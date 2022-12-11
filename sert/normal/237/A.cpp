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
ll n, m, k, t, kol = 0, ans = 0;
ll a[N], b[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t1 = -1, t2 = -2;
    cin >> k;
    fr(i, k){
      cin >> n >> m;
      if (n == t1 && m == t2){
        //cerr << n << " " << m << "\n";
        kol++;
      }
      else
      {
        ans = max(ans, kol);
        kol = 1;
        t1 = n;
        t2 = m;
      }
    }
    cout << max(ans, kol);
    return 0;
}