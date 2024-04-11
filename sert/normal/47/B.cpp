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

string s[3];
string ans;

int main()
{
    for (int i = 0; i < 3; i++)
    {
      cin >> s[i];
      if (s[i][1] == '>')
        swap(s[i][0], s[i][2]);
      s[i][1] = '<';
    }
    if (s[0][0] != s[1][0] && s[1][0] != s[2][0] && s[2][0] != s[0][0])
      ret("Impossible");
    if (s[0][0] == s[1][0])
      cout << s[0][0] << s[2][0] << s[2][2];
    if (s[0][0] == s[2][0])
      cout << s[0][0] << s[1][0] << s[1][2];
    if (s[1][0] == s[2][0])
      cout << s[1][0] << s[0][0] << s[0][2];
    return 0;
}