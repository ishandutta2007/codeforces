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
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    int a[300000], sum = 0, b[300000];
    int n;
    cin >> n;
    fr(i, n) {cin >> a[i]; sum += a[i];}
    if (sum % n != 0) ret("0");
    sum /= n;
    int ans = 0;
    fr(i, n)
      if(a[i] == sum)
        {
          b[ans] = i;
          ans++;
        }
    printf("%d\n", ans);
    fr(i, ans)
      cout << b[i] + 1 << " ";
    return 0;
}