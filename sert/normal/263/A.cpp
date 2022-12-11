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
const ll N = 1e6+5;
const ll M = 1e3+5;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int n, m, h, k, p;
int len, kol, ans;
int a[N];
string s;

int main()
{
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++){
            cin >> h;
            if (h == 1){
                cout << (abs(i - 3) + abs(j - 3));
            }
        }

    return 0;
}