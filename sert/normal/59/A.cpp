#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int d = 'A' - 'a';
    int m = 0, b = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
      if (s[i] >= 'a' && s[i] <= 'z')
        m++;
      else
        b++;
   // cout << m << " " << b << " ";
    if (m >= b)
      for (int i = 0; i < s.length(); i++)
        if (s[i] < 'a' || s[i] > 'z')
          s[i] -= d;
    if (m < b)
      for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
          s[i] += d;

    cout << s;
    return 0;
}