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
    int a[100], n, mn, ans = -1;
    cin >> n;
    fr(i, n)
      cin >> a[i];
    sort(a, a + n);
    if(a[n - 1] == a[0])
      ret("NO");
    int j = 1;
    while(a[j] == a[j - 1])
      j++;
    cout << a[j];

    return 0;
}