#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, x, y, xx, yy;
    string s[5];
    s[0] =  "Sheldon";
    s[1] =  "Leonard";
    s[2] =  "Penny";
    s[3] =  "Rajesh";
    s[4] =  "Howard";
    cin >> n;
    k = 4;
    int kef = 1;
    int p = 0;
    while (p < n)
    {
      k = (k + 1) % 5;
      if (k == 0 && p != 0) kef *= 2;
      p += kef;
    }
    cout << s[k];
}