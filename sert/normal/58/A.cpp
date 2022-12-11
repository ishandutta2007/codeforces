#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int n;
    string k, s = "hello@";
    int p = 0;
    cin >> k;
    for (int i = 0; i < k.length(); i++)
    {
      if (k[i] == s[p])
        p++;
    }
    //cout << p;
    if (p == 5)
      cout << "YES";
    else
      cout << "NO";
    return 0;
}