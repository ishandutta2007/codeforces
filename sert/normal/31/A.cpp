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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[100], n;
    cin >> n;
    fr(i, n) cin >> a[i];
    fr(i, n)
      fr(j, n)
        fr(k, n)
          if(j != k && i != j && i != k && a[i] == a[j] + a[k])
          {
            printf("%d %d %d", i + 1, j + 1, k + 1);
            return 0;
          }
    cout << -1;
    return 0;
}