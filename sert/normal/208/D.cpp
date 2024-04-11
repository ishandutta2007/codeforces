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
ll n, m, p, k, mx = 0, kol = 0, mn = 0, len = 0;
ll a[300000], b[1000000], u[1000] = {0};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, 5)
        cin >> b[i];
    b[5] = 1e16;
    ll sum = 0;
    fr(i, n)
    {
        sum += a[i];
        while(true)
        {
            cerr << sum << "\n";
            m = -1;
            while (b[m + 1] <= sum)
                m++;
            if (m == -1)
                break;
            if (m != 4)
            {
                sum -= b[m];
                u[m] += 1;
            }
            else
            {
                k = sum / b[m];
                sum -= b[m] * k;
                u[m] += k;
            }
        }
    }
    fr(i, 5)
        cout << u[i] << " ";
    cout << "\n" << sum;
    return 0;
}