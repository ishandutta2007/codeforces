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
    int a[101], n, mn, ans = -1, time = 0;
    cin >> n;
    fr(i, n)
      cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    int kol = 0;
    int j = 0;
    while (j < n && sum + a[j] <= 350)
    {
      sum += a[j];
      j++;
      kol++;
    }
    while (j < n && sum + a[j] <= 710)
    {
      time += sum + a[j] - 350;
      sum += a[j];
      j++;
      kol++;
    }
    printf("%d %d", kol, time);
    return 0;
}