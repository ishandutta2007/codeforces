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
    int u[100][100], v[100], d[100];
    int n;
    cin >> n;
    fr(i, n) cin >> v[i] >> d[i];
    fr(i, n) fr(j, n) u[i][j] = 0;
    fr(i, n)
      fr(j, n)
        if(v[i] + d[i] == v[j])
          u[i][j] = 1;
    fr(i, n)
      fr(j, n)
        if(u[i][j] * u[j][i] == 1) ret("YES");
    cout << "NO";
    return 0;
}