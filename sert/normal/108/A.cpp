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

const ll inf = 1e9;
const ld eps = 1e-9;
const ll N = 1e6;
const ll M = 1e3;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

void minuta (int &h, int &m){
    m++;
    if (m == 60){
        m = 0;
        h = (h + 1) % 24;
    }
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int h, m;
    char ch;
    cin >> h >> ch >> m;
    while(true){
        minuta(h, m);
        if (h % 10 == m / 10 && h / 10 == m % 10){
            if (h <= 9) cout << "0";
            cout << h << ":";
            if (m <= 9) cout << "0";
            cout << m << "\n";
            return 0;

        }
    }

    return 0;
}