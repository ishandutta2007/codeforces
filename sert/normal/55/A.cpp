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

bool _less(char a, char c)
{
  return a > c;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string a, h;
    char b[100000];
    int u[1000] = {0};
    int n, k = 1, i = 1;
    cin >> n;
    u[0] = 1;
    u[1] = 1;
    while(k != 0 || i != n)
    {
      i = i % n + 1;
      k = (k + i) % n;
      u[k] = 1;
    }
    fr(i, n)
      if(u[i] == 0)
        ret("NO");
    cout << "YES";

}