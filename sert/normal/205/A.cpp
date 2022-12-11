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

bool one = false;
int n, t, mn = 2000000000, num;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == mn)
            one = true;
        if (t < mn)
        {
            mn = t;
            one = false;
            num = i + 1;
        }
    }
    if (one)
        ret("Still Rozdil");
    cout << num;
    return 0;
}