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
#define wrp(a, b) cout << a << " " << b << " "



typedef long long ll;
typedef long double ld;
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 2e6;
const ll M = 2e6;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int n, k, a, b, c, d;
bool u[N];
ll h, j, h1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    u[1] = true;
    fab(i, 2, 1000){
      if (!u[i]){
        j = i * i;
        if (j < 0) continue;
        while(j <= 1000000){
          u[j] = true;
          j += i;

        }
      }
    }
    cin >> n;
    fr(i, n){
      cin >> h1;
      h = sqrtl(h1);
      //cerr << h << "\n";
      if (u[h] || h1 != h * h) cout << "NO\n"; else cout << "YES\n";

    }
}