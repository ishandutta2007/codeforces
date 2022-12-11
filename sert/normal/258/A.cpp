#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
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

const ll inf = 1e9+7;
const ld eps = 1e-9;
const ll N = 1e6+4;
const ll M = 1e3+4;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

ll a[N];
bool u[N];
string s, s1, s2;
int n, m, h, l, r, k;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s;
    bool fnd = false;
    fr(i, s.length() - 1){
        if (s[i] == '0' && !fnd)
            fnd = true;
        else
            cout << s[i];


    }

    if (fnd)
        cout << s[s.length() - 1];

    return 0;
}