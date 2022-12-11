#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

string s;
int n, m, p, k;
int a[300000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    fr(i, 2 * n + 1)
        cin >> a[i];
    fr(i, 2 * n + 1)
        if (i % 2 == 1)
            if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1] && k > 0)
            {
                k--;
                a[i]--;

            }
    fr(i, 2 * n + 1)
        cout << a[i] << " ";
    return 0;
}