#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

int nod(int a, int b)
{
  if (a % b == 0) return b;
  else return nod(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, x, y, xx, yy;
    string s;
    k = 1;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == s[i - 1]) k++; else k = 1;
      if (k >= 7) {cout << "YES"; return 0;}
    }
    cout << "NO";
}