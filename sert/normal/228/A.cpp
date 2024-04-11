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
#define wr(a, b) cout << a << " " << b << "\n"



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

int a[4], n, ans;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    n = 4;
    fr(i, n) cin >> a[i];
    sort(a, a + n);
    fab(i, 1, n - 1) if (a[i] == a[i - 1]) ans++;
    cout << ans;
    return 0;
}