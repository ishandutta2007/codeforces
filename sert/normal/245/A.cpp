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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, a = 0, b = 0, na = 0, nb = 0, k, h, nh;
    cin >> n;
    fr(i, n)
    {
        cin >> k >> h >> nh;
        if (k == 1) {a += h; na += nh;}
        else {b += h; nb += nh;}
    }
    if (a >= na) cout << "LIVE\n"; else cout << "DEAD\n";
    if (b >= nb) cout << "LIVE\n"; else cout << "DEAD\n";
    return 0;
}