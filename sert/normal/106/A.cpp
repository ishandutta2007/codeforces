#include <iostream>

using namespace std;

int main()
{
    char c;
    string s, k;
    cin >> c;
    cin >> s >> k;
    int a, b;
    if (s[0] == '6') a = 0;
    if (s[0] == '7') a = 1;
    if (s[0] == '8') a = 2;
    if (s[0] == '9') a = 3;
    if (s[0] == 'T') a = 4;
    if (s[0] == 'J') a = 5;
    if (s[0] == 'Q') a = 6;
    if (s[0] == 'K') a = 7;
    if (s[0] =='A') a = 8;
    if (k[0] =='6') b = 0;
    if (k[0] =='7') b = 1;
    if (k[0] == '8') b = 2;
    if (k[0] == '9') b = 3;
    if (k[0] == 'T') b = 4;
    if (k[0] == 'J') b = 5;
    if (k[0] == 'Q') b = 6;
    if (k[0] == 'K') b = 7;
    if (k[0] == 'A') b = 8;
    if (s[1] == k[1])
      if (a > b)
        cout << "YES";
      else
        cout << "NO";
    else
      if (s[1] == c)
        cout << "YES";
      else
        cout << "NO";
    return 0;
}