#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[200000];
string s;
int n, p, t, m;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n == 0 && m != 0) ret("Impossible");
    if (m == 0) {cout << n << " " << n; return 0;}
    cout << n + m - min(n, m) << " ";
    cout << n + m - 1;
    return 0;
}